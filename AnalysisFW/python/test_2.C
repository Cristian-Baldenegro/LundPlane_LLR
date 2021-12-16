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



   histosTH1F["reco_efficiency_PF"] = new TH1F("reco_efficiency_PF", "reco_efficiency_PF",11,0.,1.1);
   histosTH1F["reco_efficiency_charged"] = new TH1F("reco_efficiency_charged", "reco_efficiency_charged",11,0.,1.1);

   histosTH2F["Lund plane raw splittings"] = new TH2F("Lund plane raw splittings", "Lund plane raw splittings", 40, 0, 6.0, 40, 0.6, 7);
   histosTH2F["Lund plane raw kT vs theta"] = new TH2F("Lund plane raw kT vs theta", "Lund plane raw kT vs theta", 40, 0, 6.0, 40, -3, 5.5);

   histosTH2F["Lund plane raw splittings charged"] = new TH2F("Lund plane raw splittings charged", "Lund plane raw splittings charged", 40, 0, 6.0, 40, 0.693, 7);
   histosTH2F["Lund plane raw kT vs theta charged"] = new TH2F("Lund plane raw kT vs theta charged", "Lund plane raw kT vs theta charged", 40, 0, 6.0, 40, -3, 5.5);

   histosTH2F["Lund plane raw splittings gen"] = new TH2F("Lund plane raw splittings gen", "Lund plane raw splittings gen", 40, 0, 6.0, 40, 0.693, 7);
   histosTH2F["Lund plane raw kT vs theta gen"] = new TH2F("Lund plane raw kT vs theta gen", "Lund plane raw kT vs theta gen", 40, 0, 6.0, 40, -3, 5.5);

   histosTH2F["Lund plane raw splittings charged gen"] = new TH2F("Lund plane raw splittings charged gen", "Lund plane raw splittings charged gen", 40, 0, 6.0, 40, 0.693, 7);
   histosTH2F["Lund plane raw kT vs theta charged gen"] = new TH2F("Lund plane raw kT vs theta charged gen", "Lund plane raw kT vs theta charged gen", 40, 0, 6.0, 40, -3, 5.5);

   histosTH1F["theta_highKt"] =  new TH1F("theta_highKt", "theta_highKt",10,0., 4.0);
   histosTH1F["theta_lowKt"] =  new TH1F("theta_lowKt", "theta_lowKt",20,0., 6.0);

   histosTH1F["kT_alltheta"] =  new TH1F("kT_alltheta", "kT_alltheta",20,-1.0, 6.0);

   histosTH1F["theta_highKt_charged"] =  new TH1F("theta_highKt_charged", "theta_highKt_charged",10,0., 4.0);
   histosTH1F["theta_lowKt_charged"] =  new TH1F("theta_lowKt_charged", "theta_lowKt_charged",20,0., 6.0);

   histosTH1F["kT_alltheta_charged"] =  new TH1F("kT_alltheta_charged", "kT_alltheta_charged",20,-1.0, 6.0);

   histosTH2F["response kT neutral+charged"] = new TH2F("response kT neutral+charged", "", 18, -1, 5, 18, -1, 5);
   histosTH2F["response theta neutral+charged"] = new TH2F("response theta neutral+charged", "", 18, 0, 6.0, 18, 0, 6.0);

   histosTH1F["kT_gen_spectrum"] = new TH1F("kT_gen_spectrum", "", 18, -1, 5);
   histosTH1F["theta_gen_spectrum"] = new TH1F("theta_gen_spectrum", "", 18, 0, 6.0);

   histosTH2F["response kT charged"] = new TH2F("response kT charged", "", 18, -1, 5, 18, -1, 5);
   histosTH2F["response theta charged"] = new TH2F("response theta charged", "", 18, 0, 6.0, 18, 0, 6.0);


   histosTH1F["kT_charged_gen_spectrum"] = new TH1F("kT_charged_gen_spectrum", "", 18, -1, 5);
   histosTH1F["theta_charged_gen_spectrum"] = new TH1F("theta_charged_gen_spectrum", "", 18, 0, 6.0);

   histosTH2F["Lund_plane_reco_all"] = new TH2F("Lund_plane_reco_all", "", 18, 0, 6.0, 18, -1, 5);
   histosTH2F["Lund_plane_reco_matched"] = new TH2F("Lund_plane_reco_matched", "", 18, 0, 6.0, 18, -1, 5);
   histosTH2F["Lund_plane_gen_all"] = new TH2F("Lund_plane_gen_all", "", 18, 0, 6.0, 18, -1, 5);
   histosTH2F["Lund_plane_gen_matched"] = new TH2F("Lund_plane_gen_matched", "", 18, 0, 6.0, 18, -1, 5);

   histosTH2F["purities_2D"] = new TH2F("purities_2D", "", 18, 0, 6.0, 18, -1, 5);
   histosTH2F["efficiencies_2D"] = new TH2F("efficiencies_2D", "", 18, 0, 6.0, 18, -1, 5);

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
   if ( events->nPFJetsCHS() < 2) continue;
   for (int i = 0; i < events->nPFJetsCHS(); i++)
   {
     auto jet = events->pfjetchs(i);
//   cout << jet1.lha() << endl;
     auto z = jet.z();
     auto theta = jet.theta();
     auto kT = jet.kT();


     auto z_charged = jet.z_charged();
     auto theta_charged = jet.theta_charged();
     auto kT_charged = jet.kT_charged();

     if (z.size()> 0 && jet.pt() > 500 && fabs(jet.y()) < 2.0 && z_charged.size() > 0 && fabs(jet.eta()) < 2.0 )
      {
        for (unsigned i = 0; i < z.size(); ++i)
        {
          histosTH2F["Lund plane raw splittings"]->Fill(log(0.4/theta.at(i)), log(1/z.at(i)) );
          histosTH2F["Lund plane raw kT vs theta"]->Fill(log(0.4/theta.at(i)), log(kT.at(i)) );

          if (log(kT.at(i))>2) histosTH1F["theta_highKt"]->Fill(log(0.4/theta.at(i)));
          if (log(kT.at(i))<2 && log(kT.at(i)) > -1) histosTH1F["theta_lowKt"]->Fill(log(0.4/theta.at(i)));
          histosTH1F["kT_alltheta"]->Fill(log(kT.at(i)));

        }

        for (unsigned i = 0; i < z_charged.size(); ++i)
        {
          histosTH2F["Lund plane raw splittings charged"]->Fill(log(0.4/theta_charged.at(i)), log(1/z_charged.at(i)) );
          histosTH2F["Lund plane raw kT vs theta charged"]->Fill(log(0.4/theta_charged.at(i)), log(kT_charged.at(i)) );
          if (log(kT_charged.at(i))>2) histosTH1F["theta_highKt_charged"]->Fill(log(0.4/theta_charged.at(i)));
          if (log(kT_charged.at(i))<2 && log(kT_charged.at(i)) > -1 ) histosTH1F["theta_lowKt_charged"]->Fill(log(0.4/theta_charged.at(i)));
          histosTH1F["kT_alltheta_charged"]->Fill(log(kT_charged.at(i)));
        }

     }
    }

//   if ( events->nPFJetsCHS < 2) continue;
   for (int i = 0; i < 2; i++)
   {
     auto jet = events->genjet(i);
   //cout << jet.lha() << endl;
     auto z = jet.z();
     auto theta = jet.theta();
     auto kT = jet.kT();

     auto z_charged = jet.z_charged();
     auto theta_charged = jet.theta_charged();
     auto kT_charged = jet.kT_charged();
//    cout << jet.pt() << endl;

     if (z.size()> 0 && jet.pt() > 500  && z_charged.size() > 0 && fabs(jet.y()) < 2.0 )
      {
        for (unsigned i = 0; i < z.size(); ++i)
        {
          histosTH2F["Lund plane raw splittings gen"]->Fill(log(0.4/theta.at(i)), log(1/z.at(i)) );
          histosTH2F["Lund plane raw kT vs theta gen"]->Fill(log(0.4/theta.at(i)), log(kT.at(i)) );
//          cout << eta2.at(i)-jet.eta() << " " << kT.at(i) << endl; 
        }

        for (unsigned i = 0; i < z_charged.size(); ++i)
        {
          histosTH2F["Lund plane raw splittings charged gen"]->Fill(log(0.4/theta_charged.at(i)), log(1/z_charged.at(i)) );
          histosTH2F["Lund plane raw kT vs theta charged gen"]->Fill(log(0.4/theta_charged.at(i)), log(kT_charged.at(i)) );
        }

     }
  }

   vector<double> eta2_matched1, phi2_matched1; // matched splittings det to MC
   vector<double> eta2_matched2, phi2_matched2; //matched splittings MC to det

   vector<int> index_matched1, index_matched2; //det-level indices for matched splittings, matched1 = det-to-MC, matched2 = MC-to-det

   for (int k = 0; k < 2; k++) // det-level jets
   {
     auto jet_reco = events->pfjetchs(k);

     auto z_reco = jet_reco.z();
     auto theta_reco = jet_reco.theta();
     auto kT_reco = jet_reco.kT();
     auto eta2_reco = jet_reco.eta2_splitting();
     auto phi2_reco = jet_reco.phi2_splitting();

     auto eta2_charged_reco = jet_reco.eta2_splitting_charged();
     auto phi2_charged_reco = jet_reco.eta2_splitting_charged();

     auto z_charged_reco = jet_reco.z_charged();
     auto theta_charged_reco = jet_reco.theta_charged();
     auto kT_charged_reco = jet_reco.kT_charged();

     if ( jet_reco.genidx() == -1 ) continue; //if det-level jet is not matched, skip
 
     auto jet_gen = events->genjet(jet_reco.genidx());
     auto z_gen = jet_gen.z();
     auto theta_gen = jet_gen.theta();
     auto kT_gen = jet_gen.kT();
     auto eta2_gen = jet_gen.eta2_splitting();
     auto phi2_gen = jet_gen.phi2_splitting();


     auto z_charged_gen = jet_gen.z_charged();
     auto theta_charged_gen = jet_gen.theta_charged();
     auto kT_charged_gen = jet_gen.kT_charged();
     auto eta2_charged_gen = jet_gen.eta2_charged();
     auto phi2_charged_gen = jet_gen.phi2_charged();

     if  (!(z_charged_gen.size()> 0 && jet_gen.pt() > 400 && fabs(jet_gen.y()) < 2.5 && z_charged_reco.size() > 0 )) continue;
//     cout << jet_reco.phi()- jet_gen.phi() << endl;


/*     histosTH2F["response kT charged"]->Fill(log(kT_charged_gen.at(index_true)), log(kT_charged_reco.at(index_reco)));
     histosTH1F["kT_charged_gen_spectrum"]->Fill(log(kT_charged_gen.at(index_true)));
     histosTH2F["response theta charged"]->Fill(log(0.4/theta_charged_gen.at(index_true)), log(0.4/theta_charged_reco.at(index_reco)));
     histosTH1F["theta_charged_gen_spectrum"]->Fill(log(0.4/theta_charged_gen.at(index_true)));
     histosTH1F["kT_charged_gen_spectrum"]->Fill(log(kT_charged_gen.at(index_true)));
*/
     for (unsigned i = 0; i < z_charged_gen.size(); ++i) // loop over gen-level splittings
     {

      if (log(kT_charged_gen.at(i)) < -2. || log(kT_charged_gen.at(i)) > 6) continue; //gen-level phase-space
      if (log(0.4/theta_charged_gen.at(i)) < 0. || log(0.4/theta_charged_gen.at(i)) > 6) continue; //gen-level phase-space


      float dR_max = 0.1;
      int index_true = -1;
      int index_reco = -1;
      float kT_min = 0.5;
      float kT_ratio = 0.5;
/*      cout << "=================== " << i << endl;
      cout << "gen-level splitting " << i << endl;
      cout << "=================== " << i << endl;*/
      for (unsigned j = 0; j < z_charged_reco.size(); ++j) //loop over reco-level splittings
      {
       if (log(kT_charged_reco.at(j)) < -1. || log(kT_charged_reco.at(j)) > 6) continue;
       if (log(0.4/theta_charged_reco.at(j)) < 0. || log(0.4/theta_charged_reco.at(j)) > 5) continue;
//       cout << "det-level splitting " << j << endl;
       float dphi = fabs(phi2_charged_reco.at(j) - phi2_charged_gen.at(i));
       float deta = eta2_charged_reco.at(j) - eta2_charged_gen.at(i);
       if (dphi > TMath::Pi()) dphi = 2.*TMath::Pi() - dphi;
       float dR = std::sqrt(dphi*dphi + deta*deta);
       kT_ratio = min(kT_charged_reco.at(j),kT_charged_gen.at(i))/max(kT_charged_reco.at(j),kT_charged_gen.at(i));
//       cout << "det-level splitting " << j << " jetRecoPhi " <<  jet_reco.phi() << " recoSplitPhi " << phi2_charged_reco.at(j) << "jetGenPhi " << jet_gen.phi() << "genSplitPhi " << phi2_charged_gen.at(i)  << endl;
//       cout << "det-level splitting " << j << " jetRecoPhi " <<  jet_reco.jetPhiCA_charged() << " recoSplitPhi " << phi2_charged_reco.at(j) << "jetGenPhi " << jet_gen.jetPhiCA_charged() << "genSplitPhi " << phi2_charged_gen.at(i)  << endl;       
       if (fabs(deta) < fabs(dR_max) && kT_ratio > kT_min) //find best pair
       {
         dR_max = fabs(deta);
         index_true = i;
         index_reco = j;
         kT_min = kT_ratio;
       }//endif
      }//end for

       if ( index_reco == -1 || index_true == -1 ) continue;
       int index_true_mc = -1;
       float dR_max_det = 0.1;
       kT_min = 0.1;
       kT_ratio = 0.5;
       for (unsigned l = 0; l < z_charged_gen.size(); ++l) // loop over gen-level splitings, check if the previous match is true the other way around
       {
         if (log(kT_charged_gen.at(l)) < -2 || log(kT_charged_gen.at(l)) > 6) continue;
         if (log(0.4/theta_charged_gen.at(l)) < 0. || log(0.4/theta_charged_gen.at(l)) > 6) continue;

         float dphi = fabs(phi2_charged_reco.at(index_reco) - phi2_charged_gen.at(l));
         float deta = eta2_charged_reco.at(index_reco) - eta2_charged_gen.at(l);
         if (dphi > TMath::Pi()) dphi = 2.*TMath::Pi() - dphi;
         float dR = std::sqrt(dphi*dphi + deta*deta);
         kT_ratio = min(kT_charged_reco.at(index_reco),kT_charged_gen.at(l))/max(kT_charged_reco.at(index_reco),kT_charged_gen.at(l));      
         if (fabs(deta) < fabs(dR_max_det) && kT_ratio > kT_min  ) //find best pair
         {
           dR_max_det = fabs(deta);
           index_true_mc = l;
           kT_min = kT_ratio;
         }//endif
       }//end for
      if ( index_true != index_true_mc ) continue;
//     cout << "index_reco " << index_reco << " dR " << dR_max << " kT_ratio " << kT_min << endl;
     histosTH2F["response kT charged"]->Fill(log(kT_charged_gen.at(index_true)), log(kT_charged_reco.at(index_reco)));
     histosTH1F["kT_charged_gen_spectrum"]->Fill(log(kT_charged_gen.at(index_true)));
     histosTH2F["response theta charged"]->Fill(log(0.4/theta_charged_gen.at(index_true)), log(0.4/theta_charged_reco.at(index_reco)));
     histosTH1F["theta_charged_gen_spectrum"]->Fill(log(0.4/theta_charged_gen.at(index_true)));
     histosTH1F["kT_charged_gen_spectrum"]->Fill(log(kT_charged_gen.at(index_true)));
     }///end for


     if  (!(z_gen.size()> 0 && jet_gen.pt() > 400 && fabs(jet_gen.y()) < 2.5 && z_reco.size() > 0 )) continue;
     for (unsigned i = 0; i < z_gen.size(); ++i) // loop over gen-level splittings
     {

      if (log(kT_gen.at(i)) < -2. || log(kT_gen.at(i)) > 5) continue; //gen-level phase-space
      if (log(0.4/theta_gen.at(i)) < 0. || log(0.4/theta_gen.at(i)) > 6) continue; //gen-level phase-space

      float dR_max = 0.1;
      int index_true = -1;
      int index_reco = -1;
      float kT_min = 0.5; 
      for (unsigned j = 0; j < z_reco.size(); ++j) //loop over reco-level splittings
      {
       if (log(kT_reco.at(j)) < -1. || log(kT_reco.at(j)) > 5) continue;
       if (log(0.4/theta_reco.at(j)) < 0. || log(0.4/theta_reco.at(j)) > 6) continue;
//       histosTH2F["Lund_plane_reco_all"]->Fill(log(0.4/theta_reco.at(j)),log(0.4/theta_reco.at(j)) > 6);
       float dphi = fabs(phi2_reco.at(j) - phi2_gen.at(i));
       float deta = eta2_reco.at(j) - eta2_gen.at(i);
       if (dphi > TMath::Pi()) dphi = 2.*TMath::Pi() - dphi;
       float dR = std::sqrt(dphi*dphi + deta*deta);
       float kT_ratio = min(kT_reco.at(j),kT_gen.at(i))/max(kT_reco.at(j),kT_gen.at(i));
//       cout << "det-level splitting " << j << " jetRecoPhi " <<  jet_reco.phi() << " recoSplitPhi " << phi2_reco.at(j) << "jetGenPhi " << jet_gen.phi() << " genSplitPhi " << phi2_gen.at(i)  << " dPhi " << dphi << endl;
//       cout << "det-level splitting " << j << " dR " <<  dR << " dEta " << deta << " dPhi " << dphi  << " kT ratio " << kT_ratio << endl;
       cout << "det-level splitting " << j << " jetRecoPhi " <<  jet_reco.jetPhiCA_charged() << " recoSplitPhi " << phi2_reco.at(j) << "jetGenPhi " << jet_gen.jetPhiCA_charged() << "genSplitPhi " << phi2_gen.at(i)  << endl;
       if (dR < dR_max && kT_ratio > kT_min  ) //find best pair
       {
	 dR_max = dR;
         index_true = i;
         index_reco = j;
         kT_min = kT_ratio;
//         cout << " we have a match with dR " << dR << " and kTratio " << kT_min << endl;
       }//endif
      }//end for

       if ( index_reco == -1 || index_true == -1 ) continue;
       int index_true_mc = -1;
       float dR_max_det = 0.2;
       kT_min = 0.5;
       for (unsigned l = 0; l < z_gen.size(); ++l) // loop over gen-level splitings, check if the previous match is true the other way around
       {
         if (log(kT_gen.at(l)) < -1 || log(kT_gen.at(l)) > 5) continue;
         if (log(0.4/theta_gen.at(l)) < 0. || log(0.4/theta_gen.at(l)) > 5) continue;

         float dphi = fabs(phi2_reco.at(index_reco) - phi2_gen.at(l));
         float deta = eta2_reco.at(index_reco) - eta2_gen.at(l);
         if (dphi > TMath::Pi()) dphi = 2.*TMath::Pi() - dphi;
         float dR = std::sqrt(dphi*dphi + deta*deta);
         float kT_ratio = min(kT_reco.at(index_reco),kT_gen.at(l))/max(kT_reco.at(index_reco),kT_gen.at(l));      
         if (dR < dR_max_det && kT_ratio > kT_min ) //find best pair
         {
           dR_max_det = dR;
           index_true_mc = l;
           kT_min = kT_ratio;
         }//endif
       }//end for
      if ( index_true != index_true_mc ) continue;
     histosTH2F["response kT neutral+charged"]->Fill(log(kT_gen.at(index_true)), log(kT_reco.at(index_reco)));
     histosTH2F["response theta neutral+charged"]->Fill(log(0.4/theta_gen.at(index_true)), log(0.4/theta_reco.at(index_reco)));
     histosTH1F["theta_gen_spectrum"]->Fill(log(0.4/theta_gen.at(index_true)));
     histosTH1F["kT_gen_spectrum"]->Fill(log(kT_gen.at(index_true)));
     }///end for


/*     if  (!(z_charged_gen.size()> 0 && jet_gen.pt() > 50 && fabs(jet_gen.y()) < 2.0 && z_charged_reco.size() > 0 && fabs(jet_gen.eta() < 2.0 ))) continue;
*/

  }
 
}

  for (int i = 1; i < 19; i++) // normalization for response matrix
  {

   for (int j = 1; j < 19; j++)
   {
    histosTH2F["response kT charged"]->SetBinContent(i,j, float(histosTH2F["response kT charged"]->GetBinContent(i,j))/float(histosTH1F["kT_charged_gen_spectrum"]->GetBinContent(i)) );
    histosTH2F["response kT neutral+charged"]->SetBinContent(i,j, float(histosTH2F["response kT neutral+charged"]->GetBinContent(i,j))/float(histosTH1F["kT_gen_spectrum"]->GetBinContent(i)) );    
   }

  }

  for (int i = 1; i < 19; i++) // normalization for response matrix
  {

   for (int j = 1; j < 19; j++)
   {
    histosTH2F["response theta charged"]->SetBinContent(i,j, float((histosTH2F["response theta charged"]->GetBinContent(i,j) ))/float((histosTH1F["theta_charged_gen_spectrum"]->GetBinContent(i))) );
    histosTH2F["response theta neutral+charged"]->SetBinContent(i,j, float(histosTH2F["response theta neutral+charged"]->GetBinContent(i,j))/float(histosTH1F["theta_gen_spectrum"]->GetBinContent(i)));
   }

  }

  histosTH2F["purities_2D"] = (TH2F*) histosTH2F["Lund_plane_reco_matched"]->Clone();
  histosTH2F["purities_2D"]->Divide(histosTH1F["Lund_plane_reco_all"]);
  histosTH2F["purities_2D"]->SetName("purities_2D");

  histosTH2F["efficiencies_2D"] = (TH2F*) histosTH2F["Lund_plane_gen_matched"]->Clone();
  histosTH2F["efficiencies_2D"]->Divide(histosTH1F["Lund_plane_gen_all"]);
  histosTH2F["efficiencies_2D"]->SetName("efficiencies_");

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
