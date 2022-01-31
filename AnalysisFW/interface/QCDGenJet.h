//Authors: Lund plane LLR team

#ifndef QCDGenJet_h
#define QCDGenJet_h
#include "LundPlane_LLR/AnalysisFW/interface/QCDJet.h"
#include "LundPlane_LLR/AnalysisFW/interface/QCDPFJetBTag.h"
#include "TLorentzVector.h"

#include <vector>
using std::vector;
class QCDGenJet
{
   public:
     typedef reco::Particle::LorentzVector LorentzVector;


     //------------ Constructor ------------------------------
     QCDGenJet() {lha_=-1; width_=-1; thrust_= -1; ptD2_ = -1; multiplicity_ = -1; lha_charged_=-1; width_charged_=-1; thrust_charged_= -1; ptD2_charged_ = -1; multiplicity_charged_ = -1;}
     //------------ Destructor -------------------------------
     ~QCDGenJet() {}
     //------------ Set methods ------------------------------

     void setP4(LorentzVector fP4)               { P4_ = fP4; }
     void setLHA(float flha){ lha_ = flha;}
     void setWidth(float fwidth){ width_ = fwidth;}
     void setThrust(float fthrust){ thrust_ = fthrust;}
     void setPtD2(float fptD2){ ptD2_ = fptD2;}
     void setMultiplicity(int fmultiplicity){ multiplicity_ = fmultiplicity;}
     void setLHA_charged(float flha_charged){ lha_charged_ = flha_charged;}
     void setWidth_charged(float fwidth_charged){ width_charged_ = fwidth_charged;}
     void setThrust_charged(float fthrust_charged){ thrust_charged_ = fthrust_charged;}
     void setPtD2_charged(float fptD2_charged){ ptD2_charged_ = fptD2_charged;}
     void setMultiplicity_charged(int fmultiplicity_charged){ multiplicity_charged_ = fmultiplicity_charged;}

     const LorentzVector& p4()    const {return P4_;}
     float lha()   const {return lha_;}
     float width()   const {return width_;}
     float thrust()   const {return thrust_;}
     float ptD2()   const {return ptD2_;}
     int multiplicity()   const {return multiplicity_;}


     float lha_charged()   const {return lha_charged_;}
     float width_charged()   const {return width_charged_;}
     float thrust_charged()   const {return thrust_charged_;}
     float ptD2_charged()   const {return ptD2_charged_;}
     int multiplicity_charged()   const {return multiplicity_charged_;}


     void setZ(vector<double> dz){ z_ = dz;}
     void setKt(vector<double> dkt){ kT_ = dkt;}
     void setTheta(vector<double> dtheta){ theta_ = dtheta;}

     void setZ_charged(vector<double> dz_charged){ z_charged_ = dz_charged;}
     void setKt_charged(vector<double> dkt_charged){ kT_charged_ = dkt_charged;}
     void setTheta_charged(vector<double> dtheta_charged){ theta_charged_ = dtheta_charged;}

     void setEta2(vector<double> deta){ eta_ = deta;}
     void setPhi2(vector<double> dphi){ phi_ = dphi;}

     void setEta2_charged(vector<double> deta_charged){ eta_charged_ = deta_charged;}
     void setPhi2_charged(vector<double> dphi_charged){ phi_charged_ = dphi_charged;}

     void setJetPhi_CA(float djetphi_ca){ jetphi_CA_ = djetphi_ca;}
     void setJetPhi_CA_charged(float djetphi_ca_charged){ jetphi_CA_charged_ = djetphi_ca_charged;}


     vector<double> z()    const{return z_;}
     vector<double> kT()    const{return kT_;}
     vector<double> theta()    const{return theta_;}
     vector<double> eta2_splitting()    const{return eta_;}
     vector<double> phi2_splitting()    const{return phi_;}



     vector<double> z_charged()    const{return z_charged_;}
     vector<double> kT_charged()    const{return kT_charged_;}
     vector<double> theta_charged()    const{return theta_charged_;}
     vector<double> eta2_charged()    const{return eta_charged_;}
     vector<double> phi2_charged()    const{return phi_charged_;}


     float jetPhiCA()                  const {return jetphi_CA_;}
     float jetPhiCA_charged()                  const {return jetphi_CA_charged_;}


     float pt()                   const {return P4_.pt();}
     float e()                    const {return P4_.energy();}
     float eta()                  const {return P4_.eta();}
     float y()                    const {return P4_.Rapidity();}
     float phi()                  const {return P4_.phi();}
     float mass()                 const {return P4_.mass();}

   private:
     //------ jet 4-momentum vector------------------
     LorentzVector P4_;
     //---- lha angularity ----
     float lha_;
     //---- width ----
     float width_;
     //---- thrust ------------
     float thrust_;
     //---- ptD2 ----------
     float ptD2_;
     //---- multiplicity ---
     int multiplicity_;

     //---- lha angularity ----
     float lha_charged_;
     //---- width ----
     float width_charged_;
     //---- thrust ------------
     float thrust_charged_;
     //---- ptD2 ----------
     float ptD2_charged_;
     //---- multiplicity ---
     int multiplicity_charged_;

     vector<double> eta_;
     vector<double> phi_;

     vector<double> eta_charged_;
     vector<double> phi_charged_;


     vector<double> kT_;
     vector<double> theta_;
     vector<double> z_;
//     vector<double> efficiency_;

     vector<double> z_charged_;
     vector<double> kT_charged_;
     vector<double> theta_charged_;

     float jetphi_CA_;
     float jetphi_CA_charged_;
};
#endif
