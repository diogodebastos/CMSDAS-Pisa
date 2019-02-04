#define SusyDas2019_cxx
#include "SusyDas2019.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <utility>
#include <TStopwatch.h>
#include <TLorentzVector.h>

void SusyDas2019::Loop()
{
//   In a ROOT session, you can do:
//      root> .L SusyDas2019.C
//      root> SusyDas2019 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   hrepo.clear();
   erepo.clear();
   DeactivateUselessBranches();

   // BOOK YOUR HISTOGRAMS HERE, AND KEEP THEIR POINTERS TO AVOID LOSING ACCESS TO THEM
   // WHEN THE LOOP() FUNCTION EXITS
   
   TFile f("TnP.root","recreate");
   f.cd();
   // hrepo is a std::map<std::string, TH1F*> that we use to keep pointers
   hrepo.insert(std::make_pair("invariantMass",new TH1F("invariantMass","Invariant Mass", 60,70,130)));
   hrepo.insert(std::make_pair("LeptonProbePt",new TH1F("LeptonProbePt","Lepton Probe Pt", 200,0,200)));
   erepo.insert(std::make_pair("effLeptonPt",new TEfficiency("effLeptonPt","Efficiency Lepton Pt", 8,20,100)));
   erepo.insert(std::make_pair("effLeptonEta",new TEfficiency("effLeptonEta","Efficiency Lepton Eta", 25,-2.5,2.5)));
   erepo.insert(std::make_pair("effNvert",new TEfficiency("effNvert","Efficiency Number of Vertices", 20,0,50)));

   //hrepo.insert(std::make_pair("MuonProbePtBinned",new TH1F("MuonProbePtBinned","Muon Probe Pt", [21,40,80])));
   
   //Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries = 100000;
   Int_t LepSelPdgId = 11;   

   Long64_t nbytes = 0, nb = 0;
   TStopwatch glb_clock;
   TStopwatch loc_clock;
   long report_interval = 100000;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
//      if (jentry && jentry%report_interval==0) {
//	loc_clock.RealTime();
//	glb_clock.RealTime();
//	std::cout << Form("Processed entries: %lld out of %lld (%.1f%%)",jentry,nentries,float(jentry)/nentries*100);
//	std::cout << Form(" - inst. %.0f Hz, glob. %.0f Hz)",float(report_interval)/loc_clock.RealTime(),float(jentry)/glb_clock.RealTime()) << std::endl;
//	glb_clock.Start(false);
//	loc_clock.Start(true);
//	
//	  }
      // if (Cut(ientry) < 0) continue;

      // DO WHATEVER IS NEEDED HERE (E.G. FILL HISTOGRAMS)
      // Muons TnP
      
      if (nLepGood >= 2){
        //std::cout << "nLepGood: " << nLepGood << std::endl;
        for(int itag=0; itag<nLepGood; itag++){
          if(abs(LepGood_pdgId[itag]) == LepSelPdgId && LepGood_tightId[itag] == 1 && LepGood_relIso04[itag] < 0.15){ // Tag a muon as tight
            for(int iprobe=0; iprobe<nLepGood; iprobe++){
              if(iprobe!=itag && abs(LepGood_pdgId[iprobe]) == LepSelPdgId && LepGood_charge[iprobe]*LepGood_charge[itag] < 0){ // Probe Muon
                TLorentzVector muTagVec;
                TLorentzVector muProbeVec;
                muTagVec.SetPtEtaPhiM(LepGood_pt[itag], LepGood_eta[itag], LepGood_phi[itag], LepGood_mass[itag]);
                muProbeVec.SetPtEtaPhiM(LepGood_pt[iprobe], LepGood_eta[iprobe], LepGood_phi[iprobe], LepGood_mass[iprobe]);
                Float_t mass = (muTagVec + muProbeVec).M();
               // std::cout << "Mass: " << mass << std::endl;
                hrepo["invariantMass"]->Fill(mass);
                if(mass < 98 && mass > 82){ // ele mass cut
                //if(mass < 96 && mass > 86){ // mu mass cut
                  hrepo["LeptonProbePt"]->Fill(LepGood_pt[iprobe]);
                  erepo["effLeptonPt"]->Fill(LepGood_tightId[iprobe],LepGood_pt[iprobe]);
                  erepo["effLeptonEta"]->Fill(LepGood_tightId[iprobe],LepGood_eta[iprobe]);
                  erepo["effNvert"]->Fill(LepGood_tightId[iprobe],nVert);
                }
              }
             }
           }
          } 
        }
   // PRODUCE YOUR OUTPUT HERE (PLOTTING, SAVING HISTOGRAMS ETC.)
//   hrepo["invariantMass"]->Write();
 //  hrepo["MuonProbePt"]->Write();
  // erepo["effLeptonPt"]->Write();
   //erepo["effLeptonEta"]->Write();
   //erepo["effNvert"]->Write();
  }
  f.Write();
  f.Close();
}
