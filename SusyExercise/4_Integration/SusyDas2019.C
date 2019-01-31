#define SusyDas2019_cxx
#include "SusyDas2019.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <utility>
#include <TStopwatch.h>
#include <TLegend.h>
#include <TLorentzVector.h>

Float_t SusyDas2019::ReWeight(Float_t oldWeight){
  Float_t newWeight;

  newWeight = xsec * integratedLumi*oldWeight / sumWeightsBeforeSkimming;
  //  cout <<"*******"<< integratedLumi << "\t" << xsec << "\t" << oldWeight << endl;
  return newWeight;
}

Int_t SusyDas2019::Cut(Long64_t entry)
{

  int cut;
  if(nLepGood >= 3) cut =1;
  else cut=0;
  return cut;

}

float SusyDas2019::EvaluateLeptonMVA(int i, int pdgId, float eta){
if( abs(pdgId)==13 ) { //MUONS

// Create a set of variables and declare them to the reader
// - the variable names = branch names in the tree
//theTree->SetBranchAddress( "var4", &var4 );

  forBDTevaluation1 = LepGood_miniRelIso[i];
  forBDTevaluation2 = LepGood_relIso03[i];
  forBDTevaluation3 = LepGood_relIso04[i];
  forBDTevaluation4 = LepGood_sip3d[i];
  forBDTevaluation5 = LepGood_segmentCompatibility[i];

   return reader_mu->EvaluateMVA( "BDTG method" );
 }

if( abs(pdgId)==11 && abs(eta)<1.44) {//ELECTRONS BARREL

  forBDTevaluation1 = LepGood_miniRelIso[i];
  forBDTevaluation2 = LepGood_relIso03[i];
  forBDTevaluation3 = LepGood_relIso04[i];
  forBDTevaluation4 = LepGood_sip3d[i];
  forBDTevaluation5 = LepGood_sigmaIEtaIEta[i];
  forBDTevaluation6 = LepGood_mvaIdSpring16GP[i]; // unfortunately we don't have the same variable used in the training: LepGood_mvaIdFall17noIso[i];

   return reader_el_b->EvaluateMVA( "BDTG method" );
 }

if( abs(pdgId)==11 && abs(eta)>1.56) {//ELECTRONS ENDCAP

  forBDTevaluation1 = LepGood_miniRelIso[i];
  forBDTevaluation2 = LepGood_relIso03[i];
  forBDTevaluation3 = LepGood_relIso04[i];
  forBDTevaluation4 = LepGood_sip3d[i];
  forBDTevaluation5 = LepGood_sigmaIEtaIEta[i];
  forBDTevaluation6 = LepGood_mvaIdSpring16GP[i]; // unfortunately we don't have the same variable used in the training: LepGood_mvaIdFall17noIso[i];

   return reader_el_e->EvaluateMVA( "BDTG method" );
 }
 return -1; // catch all other cases (out of acceptance)

}

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
   
   // hrepo is a std::map<std::string, TH1F*> that we use to keep pointers
   hrepo.insert(std::make_pair("LepGood_pt",new TH1F("Pt","Pt",800,0,800)));
   hrepo.insert(std::make_pair("numberOfLeptons",new TH1F("numberOfLeptons","Number of leptons",10,-0.5,9.5)));
   hrepo.insert(std::make_pair("numberOfLeptonsCut",new TH1F("numberOfLeptonsCut","Number of leptons > 3",10,-0.5,9.5)));
   
   // FOR TAG AND PROBE
   hrepo.insert(std::make_pair("invariantMass",new TH1F("invariantMass","Invariant Mass", 60,70,130)));
   hrepo.insert(std::make_pair("LeptonProbePt",new TH1F("LeptonProbePt","Lepton Probe Pt", 200,0,200)));
   erepo.insert(std::make_pair("effLeptonPt",new TEfficiency("effLeptonPt","Efficiency Lepton Pt", 8,20,100)));
   erepo.insert(std::make_pair("effLeptonEta",new TEfficiency("effLeptonEta","Efficiency Lepton Eta", 25,-2.5,2.5)));
   erepo.insert(std::make_pair("effNvert",new TEfficiency("effNvert","Efficiency Number of Vertices", 20,0,50)));
   
   // PLOT VARIABLES
   hrepo.insert(std::make_pair("leadingLeptonPt",new TH1F("leadingLeptonPt","Leading Lepton Pt", 300,0,300)));
   hrepo.insert(std::make_pair("subLeadingLeptonPt",new TH1F("subLeadingLeptonPt","Sub-leading Lepton Pt", 300,0,300)));
   hrepo.insert(std::make_pair("flavorComb",new TH1F("flavorComb","Lepton flavour combination", 4,0,4)));
   hrepo.insert(std::make_pair("chargeCombHist",new TH1F("chargeCombHist","Lepton charge combination", 5,-2.5,2.5)));
   hrepo.insert(std::make_pair("MET",new TH1F("MET","Missing Transverse Energy", 300,0,300)));
   hrepo.insert(std::make_pair("invMass",new TH1F("invMass","Invariant Mass Leptons", 60,70,130)));
   hrepo.insert(std::make_pair("transverse_mass",new TH1F("transverse_mass","Transverse Mass", 300,0,300)));
   
   
   // METvsMLL
   // MLL
   Float_t XBin = 6;
   Float_t minX = 50;
   Float_t maxX = 500;
   Float_t stepX = (maxX-minX)/XBin;
   //MET
   Float_t YBin = 8;
   Float_t minY = 0;
   Float_t maxY = 500;
   Float_t stepY = (maxY-minY)/YBin;

   Int_t finalBin = XBin*YBin;
   hrepo.insert(std::make_pair("mllVSms",new TH1F("mllVSms","Mll vs MET", finalBin,0,finalBin)));
   hrepo.insert(std::make_pair("msVSmll",new TH1F("msVSmll","MET vs Mll", finalBin,0,finalBin)));
   //Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries = 100000;
   
   Long64_t nbytes = 0, nb = 0;
   TStopwatch glb_clock;
   TStopwatch loc_clock;
   long report_interval = 100000;

   Float_t newWeight;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      //      cout << "_________"<< genWeight << endl;
      newWeight=ReWeight(genWeight); 


      if (jentry && jentry%report_interval==0) {
	loc_clock.RealTime();
	glb_clock.RealTime();
	std::cout << Form("Processed entries: %lld out of %lld (%.1f%%)",jentry,nentries,float(jentry)/nentries*100);
	std::cout << Form(" - inst. %.0f Hz, glob. %.0f Hz)",float(report_interval)/loc_clock.RealTime(),float(jentry)/glb_clock.RealTime()) << std::endl;
	glb_clock.Start(false);
	loc_clock.Start(true);
      }
      // if (Cut(ientry) < 0) continue;

      // DO WHATEVER IS NEEDED HERE (E.G. FILL HISTOGRAMS)
      //      if (jentry% 100==0) cout << nLepGood << "\t" << newWeight << "\t" << Cut(jentry) << endl;
      hrepo["numberOfLeptons"]->Fill(nLepGood,newWeight);
      hrepo["numberOfLeptonsCut"]->Fill(nLepGood,newWeight*Cut(jentry));
      for (int i=0; i<nLepGood; i++) hrepo["LepGood_pt"]->Fill(LepGood_pt[i],newWeight);

      // Lepton TnP
      Int_t LepSelPdgId = 13;      
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


      float LepGood_newMVA[20];
      vector<Int_t> passMVA;
      for (int i=0; i<nLepGood; i++) {
       LepGood_newMVA[i] = EvaluateLeptonMVA(i,LepGood_pdgId[i],LepGood_eta[i]);
       if (LepGood_newMVA[i] > -0.15 && LepGood_pt[i] > 25) {
        passMVA.push_back(i);
       }
      }

      
      Int_t nGoodLep=0;
      Int_t chargeComb=1;
      if(passMVA.size() > 2) {
       hrepo["leadingLeptonPt"]->Fill(LepGood_pt[passMVA.at(0)]); // leading lepton
       hrepo["subLeadingLeptonPt"]->Fill(LepGood_pt[passMVA.at(1)]); // sub-leading lepton
       for(int i=0; i<3; i++){   // flavor and charge combination of pairs of leptons
        if(abs(LepGood_pdgId[passMVA.at(i)])==13){
         nGoodLep++;
         hrepo["flavorComb"]->Fill(nGoodLep);
        }
        chargeComb = chargeComb*LepGood_charge[passMVA.at(i)]; //charge combination
        hrepo["chargeCombHist"]->Fill(chargeComb);
       }
       hrepo["MET"]->Fill(met_pt); // met

       // invariant mass of pairs of identified leptons 
       TLorentzVector mu1Vec;
       TLorentzVector mu2Vec;
       Float_t mass;

       if(LepGood_pdgId[passMVA.at(0)] + LepGood_pdgId[passMVA.at(1)] == 0){
        mu1Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(0)], LepGood_eta[passMVA.at(0)], LepGood_phi[passMVA.at(0)], LepGood_mass[passMVA.at(0)]);
        mu2Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(1)], LepGood_eta[passMVA.at(1)], LepGood_phi[passMVA.at(1)], LepGood_mass[passMVA.at(1)]);
        mass = (mu1Vec + mu2Vec).M();      
       }
       if(LepGood_pdgId[passMVA.at(0)] + LepGood_pdgId[passMVA.at(2)] == 0){
        mu1Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(0)], LepGood_eta[passMVA.at(0)], LepGood_phi[passMVA.at(0)], LepGood_mass[passMVA.at(0)]);
        mu2Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(2)], LepGood_eta[passMVA.at(2)], LepGood_phi[passMVA.at(2)], LepGood_mass[passMVA.at(2)]);
        mass = (mu1Vec + mu2Vec).M();      
       }
       if(LepGood_pdgId[passMVA.at(1)] + LepGood_pdgId[passMVA.at(2)] == 0){
        mu1Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(1)], LepGood_eta[passMVA.at(1)], LepGood_phi[passMVA.at(1)], LepGood_mass[passMVA.at(1)]);
        mu2Vec.SetPtEtaPhiM(LepGood_pt[passMVA.at(2)], LepGood_eta[passMVA.at(2)], LepGood_phi[passMVA.at(2)], LepGood_mass[passMVA.at(2)]);
        mass = (mu1Vec + mu2Vec).M();      
       }
       hrepo["invMass"]->Fill(mass);

       //  transverse mass (MT) of the leading lepton and MET 
       TLorentzVector metVec;
       TLorentzVector leadingLep;
       Float_t transverse_mass;
       metVec.SetPtEtaPhiM(met_pt, met_eta, met_phi, met_mass);
       leadingLep.SetPtEtaPhiM(LepGood_pt[passMVA.at(0)], LepGood_eta[passMVA.at(0)], LepGood_phi[passMVA.at(0)], LepGood_mass[passMVA.at(0)]);
       transverse_mass = (metVec + leadingLep).Mt();
       hrepo["transverse_mass"]->Fill(transverse_mass);

       // Unroll PLOT METvsMLL
       int finalY = mass/stepY;
       int finalX = met_pt/stepX;
       
       hrepo["mllVSms"]->Fill(finalY*XBin+finalX);
       hrepo["msVSmll"]->Fill(finalX*YBin+finalY);
      }
   }

   // PRODUCE YOUR OUTPUT HERE (PLOTTING, SAVING HISTOGRAMS ETC.)
//   hrepo["numberOfLeptons"]->Print();
//   TCanvas* c = new TCanvas(hrepo["numberOfLeptons"]->GetName(),hrepo["numberOfLeptons"]->GetName(),1200,600);
//   c->Divide(2,1);
//   c->cd(1);
//   // TLegend* l = new TLegend();
//   // l->AddEntry(hrepo["numberOfLeptons"]);
//   //l->AddEntry(hrepo["numberOfLeptonsCut"]);
//   hrepo["numberOfLeptonsCut"]->Draw();
//   hrepo["numberOfLeptonsCut"]->SetLineColor(kRed);
//   hrepo["numberOfLeptonsCut"]->Draw("same");
//   c->cd(2);
   // l->Draw();
}


/*void HistoStackAllDatasets(){
  vector<string> inputFiles={
  "ZZZ",
  "TTJets_DiLepton_ext_part5",
  "ZZTo4L",
  "TTJets_DiLepton_ext_part4",
  "ZZTo2L2Q",
  "TTJets_DiLepton_ext_part3",
  "WZZ",
  "TTJets_DiLepton_ext_part2",
  "WZTo3LNu",
  "TTJets_DiLepton_ext_part1",
  "WWZ",
  "TChiWZ_500_50",
  "WWW",
  "TChiWZ_500_200",
  "WJetsToLNu_LO",
  "TChiWZ_375_285",
  "WJetsToLNu_HT800to1200_ext",
  "TChiWZ_200_50",
  "WJetsToLNu_HT800to1200",
  "TChiWZ_200_160",
  "WJetsToLNu_HT70to100",
  "TChiWZ_200_140",
  "WJetsToLNu_HT600to800_ext",
  "TChiWZ_200_110",
  "WJetsToLNu_HT600to800",
  "TBar_tch_powheg",
  "WJetsToLNu_HT400to600_ext",
  "TBar_tWch_ext",
  "WJetsToLNu_HT400to600",
  "DYJetsToLL_M5to50_HT600toInf_ext",
  "WJetsToLNu_HT2500toInf_ext",
  "DYJetsToLL_M5to50_HT600toInf",
  "WJetsToLNu_HT2500toInf",
  "DYJetsToLL_M5to50_HT400to600_ext",
  "WJetsToLNu_HT200to400_ext",
  "DYJetsToLL_M5to50_HT400to600",
  "WJetsToLNu_HT200to400_ext2",
  "DYJetsToLL_M5to50_HT200to400_ext",
  "WJetsToLNu_HT200to400",
  "DYJetsToLL_M5to50_HT200to400",
  "WJetsToLNu_HT1200to2500_ext",
  "DYJetsToLL_M5to50_HT100to200_ext",
  "WJetsToLNu_HT1200to2500",
  "DYJetsToLL_M5to50_HT100to200",
  "WJetsToLNu_HT100to200_ext",
  "DYJetsToLL_M50_LO_ext",
  "WJetsToLNu_HT100to200",
  "DYJetsToLL_M50_HT800to1200",
  "VVTo2L2Nu_ext",
  "DYJetsToLL_M50_HT70to100",
  "VVTo2L2Nu",
  "DYJetsToLL_M50_HT600to800",
  "T_tch_powheg",
  "DYJetsToLL_M50_HT400to600_ext",
  "T_tWch_ext",
  "DYJetsToLL_M50_HT400to600",
  "TToLeptons_sch",
  "DYJetsToLL_M50_HT2500toInf",
  "TTZToLLNuNu_m1to10",
  "DYJetsToLL_M50_HT200to400_ext",
  "TTZToLLNuNu_ext",
  "DYJetsToLL_M50_HT200to400",
  "TTWToLNu_ext",
  "DYJetsToLL_M50_HT1200to2500",
  "TTJets_SingleLeptonFromTbar",
  "DYJetsToLL_M50_HT100to200_ext",
  "TTJets_SingleLeptonFromT",
  "DYJetsToLL_M50_HT100to200",
  "TTJets_DiLepton_part2",
  "DYJetsToLL_M10to50_LO",
  "TTJets_DiLepton_part1"
  };

  

}
*/
