#define test_2_cxx
#include "test_2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>



using namespace std;

void test_2::Loop()
{
//   In a ROOT session, you can do:
//      root> .L test_2.C
//      root> test_2 t
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

   Long64_t nentries = fChain->GetEntriesFast();

   map<string,TH1F*> histosTH1F;
   map<string,TH2F*> histosTH2F;

   histosTH1F["jet1Pt"] = new TH1F("jet1Pt", "jet1Pt",50,500,1000);
   histosTH1F["pThat"] = new TH1F("ptHat", "PtHat",50,0,1000);
   histosTH1F["pThat_unweighted"] = new TH1F("ptHat_unweighted", "PtHat_unweighted",50,0,1000);
   histosTH1F["jet2Pt"] = new TH1F("jet2Pt", "jet2Pt",50,500,1000);
   histosTH1F["jetPtAsymmetry"] = new TH1F("jetPtAsymmetry", "jetPtAsymmetry",20,0, 1);
   histosTH1F["DeltaPhi"] = new TH1F("DeltaPhi", "DeltaPhi",32,0, M_PI);
   histosTH1F["jet1Rapidity"] =  new TH1F("jet1Rapidity", "jet1Rapidity",10,-2.0, 2.0);
   histosTH1F["jet2Rapidity"] =  new TH1F("jet2Rapidity", "jet2Rapidity",10,-2.0, 2.0);
   histosTH1F["DeltaRapidity"] =  new TH1F("DeltaRapidity", "DeltaRapidity",10,0, 4.0);

   histosTH1F["jetLHA"] =  new TH1F("jetLHA", "jetLHA",20,.0, 1.0);
   histosTH1F["jetThrust"] =  new TH1F("jetThrust", "jetThrust",20,.0, 1.0);
   histosTH1F["jetWidth"] =  new TH1F("jetWidth", "jetWidth",20,.0, 1.0);
   histosTH1F["ptD2"] =  new TH1F("ptD2", "ptD2",20,.0, 1.0);
   histosTH1F["multiplicity"] =  new TH1F("multiplicity", "multiplicity",50,.0, 50);

   histosTH1F["jetLHA_charged"] =  new TH1F("jetLHA_charged", "jetLHA_charged",20,.0, 1.0);
   histosTH1F["jetThrust_charged"] =  new TH1F("jetThrust_charged", "jetThrust_charged",20,.0, 1.0);
   histosTH1F["jetWidth_charged"] =  new TH1F("jetWidth_charged", "jetWidth_charged",20,.0, 1.0);
   histosTH1F["ptD2_charged"] =  new TH1F("ptD2_charged", "ptD2_charged",20,.0, 1.0);
   histosTH1F["multiplicity_charged"] =  new TH1F("multiplicity_charged", "multiplicity_charged",50,.0, 50);

   histosTH1F["gen_jetLHA"] =  new TH1F("gen_jetLHA", "gen_jetLHA",20,.0, 1.0);
   histosTH1F["gen_jetThrust"] =  new TH1F("gen_jetThrust", "gen_jetThrust",20,.0, 1.0);
   histosTH1F["gen_jetWidth"] =  new TH1F("gen_jetWidth", "gen_jetWidth",20,.0, 1.0);
   histosTH1F["gen_ptD2"] =  new TH1F("gen_ptD2", "gen_ptD2",20,.0, 1.0);
   histosTH1F["gen_multiplicity"] =  new TH1F("gen_multiplicity", "gen_multiplicity",50,.0, 50);

   histosTH1F["gen_jetLHA_charged"] =  new TH1F("gen_jetLHA_charged", "gen_jetLHA_charged",20,.0, 1.0);
   histosTH1F["gen_jetThrust_charged"] =  new TH1F("gen_jetThrust_charged", "gen_jetThrust_charged",20,.0, 1.0);
   histosTH1F["gen_jetWidth_charged"] =  new TH1F("gen_jetWidth_charged", "gen_jetWidth_charged",20,.0, 1.0);
   histosTH1F["gen_ptD2_charged"] =  new TH1F("gen_ptD2_charged", "gen_ptD2_charged",20,.0, 1.0);
   histosTH1F["gen_multiplicity_charged"] =  new TH1F("gen_multiplicity_charged", "gen_multiplicity_charged",50,.0, 50);



   histosTH1F["jet1PtResolutionRatio"] = new TH1F("jet1PtResolutionRatio", "jet1PtResolutionRatio",50.,0,2);


   histosTH1F["jet1PtResolution"] = new TH1F("jet1PtResolution", "jet1PtResolution",50.,-.5,0.5);
   histosTH1F["jet2PtResolution"] = new TH1F("jet2PtResolution", "jet2PtResolution",50.,-.5,0.5);

   histosTH1F["DeltaJet1Rapidity"] = new TH1F("DeltaJet1Rapidity", "DeltaJet1Rapidity",100.,-.5,.5);
   histosTH1F["DeltaJet2Rapidity"] = new TH1F("DeltaJet2Rapidity", "DeltaJet2Rapidity",100.,-.5,.5);

   histosTH1F["DeltaJet1Phi"] = new TH1F("DeltaJet1Phi", "DeltaJet1Phi",100.,-.5,.5);
   histosTH1F["DeltaJet2Phi"] = new TH1F("DeltaJet2Phi", "DeltaJet2Phi",100.,-.5,.5);

   histosTH1F["residuals_jetLHA"] = new TH1F("residuals_jetLHA", "residuals_jetLHA",50.,-1.,1.);
   histosTH1F["residuals_jetLHA_charged"] = new TH1F("residuals_jetLHA_charged", "residuals_jetLHA_charged",50.,-1.,1.);

   histosTH1F["residuals_jetWidth"] = new TH1F("residuals_jetWidth", "residuals_jetWidth",50.,-1.,1.);
   histosTH1F["residuals_jetWidth_charged"] = new TH1F("residuals_jetWidth_charged", "residuals_jetWidth_charged",50.,-1.,1.);

   histosTH1F["residuals_jetThrust"] = new TH1F("residuals_jetThrust", "residuals_jetThrust",50.,-1.,1.);
   histosTH1F["residuals_jetThrust_charged"] = new TH1F("residuals_jetThrust_charged", "residuals_jetThrust_charged",50.,-1.,1.);

   histosTH1F["residuals_jetPtD2"] = new TH1F("residuals_jetPtD2", "residuals_jetPtD2",50.,-1.,1.);
   histosTH1F["residuals_jetPtD2_charged"] = new TH1F("residuals_jetPtD2_charged", "residuals_jetPtD2_charged",50.,-1.,1.);

   histosTH1F["residuals_jetMultiplicity"] = new TH1F("residuals_jetMultiplicity", "residuals_jetMultiplicity",40,-30,10);
   histosTH1F["residuals_jetMultiplicity_charged"] = new TH1F("residuals_jetMultiplicity_charged", "residuals_jetMultiplicity_charged",40,-30,10);

   histosTH1F["reco_efficiency_PF"] = new TH1F("reco_efficiency_PF", "reco_efficiency_PF",11,0.,1.1);
   histosTH1F["reco_efficiency_charged"] = new TH1F("reco_efficiency_charged", "reco_efficiency_charged",11,0.,1.1);

   histosTH2F["Lund plane raw splittings"] = new TH2F("Lund plane raw splittings", "Lund plane raw splittings", 40, 0, 6.0, 40, 0.6, 7);
   histosTH2F["Lund plane raw kT vs theta"] = new TH2F("Lund plane raw kT vs theta", "Lund plane raw kT vs theta", 40, 0, 6.0, 40, -3, 5.5);

   TFile* output = new TFile("output.root","RECREATE");



   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //
   //QCDPFJet = events[jentry].pfjetchs[0]; 
   //cout << events->pfmjj() << endl;
   for (int i = 0; i < events->nPFJetsCHS(); i++)
   {
     auto jet = events->pfjetchs(i);
//   cout << jet1.lha() << endl;
     auto z = jet.z();
     auto theta = jet.theta();
     auto kT = jet.kT();
     if (z.size()> 0 && jet.pt() > 400 && fabs(jet.y()) < 2.0)
      {
        for (unsigned i = 0; i < z.size(); ++i)
        {
          histosTH2F["Lund plane raw splittings"]->Fill(log(0.4/theta.at(i)), log(1/z.at(i)) );
          histosTH2F["Lund plane raw kT vs theta"]->Fill(log(0.4/theta.at(i)), log(kT.at(i)) );
        }
     }
    }
  }
  output->cd();
  //histosTH1F["jet1Pt"]->Sumw2();

   for(map<string,TH1F*>::const_iterator it = histosTH1F.begin(); it != histosTH1F.end(); ++it)
      it->second->Sumw2();

  for(map<string,TH1F*>::iterator it_histo = histosTH1F.begin();
                                  it_histo != histosTH1F.end(); ++it_histo)
     (*it_histo).second->Write();

   for(map<string,TH2F*>::const_iterator it2 = histosTH2F.begin(); it2 != histosTH2F.end(); ++it2)
      it2->second->Sumw2();

  for(map<string,TH2F*>::iterator it_histo2 = histosTH2F.begin();
                                  it_histo2 != histosTH2F.end(); ++it_histo2)
     (*it_histo2).second->Write();

  output->Close();
}
