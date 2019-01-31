#include "SusyDas2019.C"


void Analyzer(std::vector<std::string> vec, Float_t lumi){ // pass luminosity in inverse femtobarns here
  bool debug=true;

  //SusyDas2019* data[vec.size()];
  std::map<string,SusyDas2019*> data;
  std::map<string,TH1F*> mStackHist;
  

  for(uint32_t i=0;i< vec.size();i++){
    
    data[vec[i]] = new SusyDas2019(vec[i],lumi*1000);
    data[vec[i]]->Loop();
    
    std::cout << "Analyzed file " << i+1 << "/" << vec.size() <<" "<< vec[i] << std::endl;
  

    for(auto const& tagHist : data[vec[i]]->hrepo){
      if(i == 0){
	TH1F* sumHist = new TH1F(*tagHist.second);
	sumHist->SetName(("SumOfAll"+(string)(tagHist.second->GetName())).c_str());
	mStackHist[tagHist.first] = sumHist;
      }// if
      else mStackHist[tagHist.first]->Add(tagHist.second);
    }// for auto 
  }// for i

  TFile* f= new TFile("outputHists.root", "RECREATE");
  for(auto const& hist : mStackHist){
    
    hist.second->Write();
    f->mkdir(hist.first.c_str());
    f->cd(hist.first.c_str());
       
    for(uint32_t i=0; i < vec.size() ; i++){
      (data[vec[i]]->hrepo)[hist.first]->SetName((hist.first+"_"+vec[i]).c_str());
      (data[vec[i]]->hrepo)[hist.first]->Write();
    }// for i
    f->cd();
    
  }//for auto
  
  
}
