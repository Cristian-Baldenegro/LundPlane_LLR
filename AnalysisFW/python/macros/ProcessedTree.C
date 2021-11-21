#define ProcessedTree_cxx
#include "ProcessedTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ProcessedTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ProcessedTree.C
//      root> ProcessedTree t
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
//

   map<string,TH1F*> histosTH1F;

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
   histosTH1F["ptD"] =  new TH1F("ptD", "ptD",20,.0, 1.0);
   histosTH1F["multiplicity"] =  new TH1F("multiplicity", "multiplicity",50,.0, 50);




   histosTH1F["jet1PtResolutionRatio"] = new TH1F("jet1PtResolutionRatio", "jet1PtResolutionRatio",50.,0,2);


   histosTH1F["jet1PtResolution"] = new TH1F("jet1PtResolution", "jet1PtResolution",50.,-.5,0.5);
   histosTH1F["jet2PtResolution"] = new TH1F("jet2PtResolution", "jet2PtResolution",50.,-.5,0.5);



   histosTH1F["DeltaJet1Rapidity"] = new TH1F("DeltaJet1Rapidity", "DeltaJet1Rapidity",100.,-.5,.5);
   histosTH1F["DeltaJet2Rapidity"] = new TH1F("DeltaJet2Rapidity", "DeltaJet2Rapidity",100.,-.5,.5);

   histosTH1F["DeltaJet1Phi"] = new TH1F("DeltaJet1Phi", "DeltaJet1Phi",100.,-.5,.5);
   histosTH1F["DeltaJet2Phi"] = new TH1F("DeltaJet2Phi", "DeltaJet2Phi",100.,-.5,.5);


   TFile* output = new TFile("output.root","RECREATE");


   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TLorentzVector jet1, jet2, genJet1, genJet2;
   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      jet1.SetXYZT(PFJetsCHS__P4__fCoordinates_fX[0], PFJetsCHS__P4__fCoordinates_fY[0], PFJetsCHS__P4__fCoordinates_fZ[0], PFJetsCHS__P4__fCoordinates_fT[0]);
      jet2.SetXYZT(PFJetsCHS__P4__fCoordinates_fX[1], PFJetsCHS__P4__fCoordinates_fY[1], PFJetsCHS__P4__fCoordinates_fZ[1], PFJetsCHS__P4__fCoordinates_fT[1]);
      genJet1.SetXYZT(GenJets__fCoordinates_fX[PFJetsCHS__genIdx_[0]], GenJets__fCoordinates_fY[PFJetsCHS__genIdx_[0]], GenJets__fCoordinates_fZ[PFJetsCHS__genIdx_[0]], GenJets__fCoordinates_fT[PFJetsCHS__genIdx_[0]]);
      genJet2.SetXYZT(GenJets__fCoordinates_fX[PFJetsCHS__genIdx_[1]], GenJets__fCoordinates_fY[PFJetsCHS__genIdx_[1]], GenJets__fCoordinates_fZ[PFJetsCHS__genIdx_[1]], GenJets__fCoordinates_fT[PFJetsCHS__genIdx_[1]]);
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      histosTH1F["pThat"]->Fill(EvtHdr__mPthat, EvtHdr__mWeight);
      histosTH1F["pThat_unweighted"]->Fill(EvtHdr__mPthat);
//      cout << PFJetsCHS__P4__fCoordinates_fT[0] << endl;
//
      cout << jet1.Pt() << endl;
      if (jet1.Pt() > 550 && jet2.Pt() > 500 && fabs(jet1.Rapidity()) < 2.0 && fabs(jet2.Rapidity()) < 2.0 )
      {

      histosTH1F["jetPtAsymmetry"]->Fill(fabs(jet1.Pt()-jet2.Pt())/fabs(jet1.Pt()+jet2.Pt()), EvtHdr__mWeight );

      histosTH1F["jet1Pt"]->Fill(jet1.Pt(), EvtHdr__mWeight);
      histosTH1F["jet2Pt"]->Fill(jet2.Pt(), EvtHdr__mWeight);

      histosTH1F["DeltaRapidity"]->Fill(fabs(jet1.Rapidity()-jet2.Rapidity()),EvtHdr__mWeight );
      histosTH1F["jet1Rapidity"]->Fill(jet1.Rapidity(), EvtHdr__mWeight);
      histosTH1F["jet2Rapidity"]->Fill(jet2.Rapidity(), EvtHdr__mWeight);

      histosTH1F["jet1PtResolutionRatio"]->Fill((jet1.Pt())/genJet1.Pt(), EvtHdr__mWeight);

      histosTH1F["jet1PtResolution"]->Fill((genJet1.Pt()-jet1.Pt())/genJet1.Pt(), EvtHdr__mWeight);
      histosTH1F["jet2PtResolution"]->Fill((genJet2.Pt()-jet2.Pt())/genJet2.Pt(), EvtHdr__mWeight);

      histosTH1F["DeltaJet1Rapidity"]->Fill(genJet1.Rapidity()-jet1.Rapidity(), EvtHdr__mWeight);
      histosTH1F["DeltaJet2Rapidity"]->Fill(genJet2.Rapidity()-jet2.Rapidity(), EvtHdr__mWeight);

      histosTH1F["DeltaJet1Phi"]->Fill(genJet1.Phi()-jet1.Phi(), EvtHdr__mWeight);
      histosTH1F["DeltaJet2Phi"]->Fill(genJet2.Phi()-jet2.Phi(), EvtHdr__mWeight);

      double delta_phi = 0.;
      if (fabs(jet1.Phi()-jet2.Phi()) < M_PI) delta_phi = fabs(jet1.Phi()-jet2.Phi());
      else delta_phi = 2*M_PI-fabs(jet1.Phi()-jet2.Phi());

      histosTH1F["DeltaPhi"]->Fill(delta_phi,EvtHdr__mWeight);

        histosTH1F["jetLHA"]->Fill(PFJetsCHS__lha_[0], EvtHdr__mWeight);
        histosTH1F["jetThrust"]->Fill(PFJetsCHS__thrust_[0], EvtHdr__mWeight);
        histosTH1F["jetWidth"]->Fill(PFJetsCHS__width_[0], EvtHdr__mWeight);
        histosTH1F["ptD"]->Fill(PFJetsCHS__QGPtD_[0], EvtHdr__mWeight);
        histosTH1F["multiplicity"]->Fill(PFJetsCHS__QGMul_[0], EvtHdr__mWeight);


        histosTH1F["jetLHA"]->Fill(PFJetsCHS__lha_[1], EvtHdr__mWeight);
        histosTH1F["jetThrust"]->Fill(PFJetsCHS__thrust_[1], EvtHdr__mWeight);
        histosTH1F["jetWidth"]->Fill(PFJetsCHS__width_[1], EvtHdr__mWeight);
        histosTH1F["ptD"]->Fill(PFJetsCHS__QGPtD_[1], EvtHdr__mWeight);
        histosTH1F["multiplicity"]->Fill(PFJetsCHS__QGMul_[1], EvtHdr__mWeight);


    }   
   }

  output->cd();
  //histosTH1F["jet1Pt"]->Sumw2();
   for(map<string,TH1F*>::const_iterator it = histosTH1F.begin(); it != histosTH1F.end(); ++it)
      it->second->Sumw2();

  for(map<string,TH1F*>::iterator it_histo = histosTH1F.begin();
                                  it_histo != histosTH1F.end(); ++it_histo)
     (*it_histo).second->Write();
  output->Close();
}
