//Author K. Kousouris
//Modified by: S. Ganguly

#ifndef QCDPFJet_h
#define QCDPFJet_h
#include "LundPlane_LLR/AnalysisFW/interface/QCDJet.h"
#include "LundPlane_LLR/AnalysisFW/interface/QCDPFJetBTag.h"
#include "TLorentzVector.h"
#include <vector>

using std::vector;
class QCDPFJet : public QCDPFJetBTag {
   public:
     //------------ Constructor ------------------------------
     QCDPFJet() {chf_=0;nhf_=0;nemf_=0;cemf_=0;muf_=0;chm_=0;nhm_=0;phm_=0;elm_=0;mum_=0,cm_=0; lha_=-1; width_=-1; thrust_= -1; ptD2_ = -1; multiplicity_ = -1; lha_charged_=-1; width_charged_=-1; thrust_charged_= -1; ptD2_charged_ = -1; multiplicity_charged_ = -1;}
     //------------ Destructor -------------------------------
     ~QCDPFJet() {}
     //------------ Set methods ------------------------------
     void setJetPhi_CA(float djetphi_ca){ jetphi_CA_ = djetphi_ca;}
     void setJetPhi_CA_charged(float djetphi_ca_charged){ jetphi_CA_charged_ = djetphi_ca_charged;}

     void setFrac(float fchf, float fnhf, float fnemf, float fcemf, float fmuf)  {chf_ = fchf; nhf_ = fnhf; nemf_ = fnemf; cemf_ = fcemf; muf_ = fmuf;}
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

     void setMulti(int fncand, int fchm, int fnhm, int fphm, int felm, int fmum, int fcm) {ncand_ = fncand; chm_ = fchm; nhm_ = fnhm; phm_ = fphm; elm_ = felm; mum_ = fmum; cm_ = fcm; }
     void setBetaPrime(float fbetaPrime) {betaPrime_ = fbetaPrime;}
     void setHFFrac(float fhf_hf, float fhf_phf) {hf_hf_ = fhf_hf; hf_phf_ = fhf_phf;}
     void setHFMulti(int fhf_hm, int fhf_phm) {hf_hm_ = fhf_hm; hf_phm_ = fhf_phm;}
     void setVtxInfo(int mpuTrk, int mlvTrk, int mjtTrk) { mpuTrk_ = mpuTrk; mlvTrk_ = mlvTrk; mjtTrk_ = mjtTrk;} // Juska
     void setHO(float hof) {hof_ = hof;} // Juska
     void SetPUJetId(float pujid) { pujid_ = pujid; }
     void setKt(vector<double> dkt){ kT_ = dkt;}
     void setTheta(vector<double> dtheta){ theta_ = dtheta;}
//     void setPurity(vector<double> dpurity){ purity_ = dpurity;}
     void setZ(vector<double> dz){ z_ = dz;}

     void setZ_charged(vector<double> dz_charged){ z_charged_ = dz_charged;}
     void setKt_charged(vector<double> dkt_charged){ kT_charged_ = dkt_charged;}
     void setTheta_charged(vector<double> dtheta_charged){ theta_charged_ = dtheta_charged;}

     void setEta2(vector<double> deta){ eta_ = deta;}
     void setPhi2(vector<double> dphi){ phi_ = dphi;}

     void setEta2_charged(vector<double> deta_charged){ eta_charged_ = deta_charged;}
     void setPhi2_charged(vector<double> dphi_charged){ phi_charged_ = dphi_charged;}


     //------------ Get methods ------------------------------
     float betaPrime() const {return betaPrime_;}
     float chf()      const {return chf_;}
     float nhf()      const {return nhf_;}
     float nemf()      const {return nemf_;}
     float cemf()      const {return cemf_;}
     float muf()      const {return muf_;}
     float hf_hf()    const {return hf_hf_;}
     float hf_phf()   const {return hf_phf_;}



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

     float jetPhiCA()                  const {return jetphi_CA_;}
     float jetPhiCA_charged()                  const {return jetphi_CA_charged_;}

     vector<double> z()    const{return z_;}
     vector<double> kT()    const{return kT_;}
     vector<double> theta()    const{return theta_;}
     vector<double> eta2_splitting()    const{return eta_;}
     vector<double> phi2_splitting()    const{return phi_;}

     vector<double> z_charged()    const{return z_charged_;}
     vector<double> kT_charged()    const{return kT_charged_;}
     vector<double> theta_charged()    const{return theta_charged_;}
     vector<double> eta2_splitting_charged()    const{return eta_charged_;}
     vector<double> phi2_splitting_charged()    const{return phi_charged_;}



     int chm()        const {return chm_;}
     int nhm()        const {return nhm_;}
     int phm()        const {return phm_;}
     int elm()        const {return elm_;}
     int mum()        const {return mum_;}
     int hf_hm()      const {return hf_hm_;}
     int hf_phm()     const {return hf_phm_;}
     int ncand()      const {return ncand_;}

     int mpuTrk()     const {return mpuTrk_;} // Juska
     int mlvTrk()     const {return mlvTrk_;} //
     int mjtTrk()     const {return mjtTrk_;} //
     float hof()      const {return hof_;}    //

     float PUJetId()  const { return pujid_ ;}

   private:
     //---- charged hadron energy fraction ----
     float chf_;
     //---- neutral hadron energy fraction ----
     float nhf_;
     //---- photon energy fraction ------------
     float nemf_;
     //---- electron energy fraction ----------
     float cemf_;
     //---- muon energy fraction --------------
     float muf_;
     //-----HF Hadron Fraction ---------------
     float hf_hf_;
     //-----HF Photon Fraction ------------
     float hf_phf_;
     //-----HF Hadron Multiplicity---------
     int hf_hm_;
     //-----HF Photon Multiplicity --------
     int hf_phm_;
     //---- charged hadron multiplicity -------
     int chm_;
     //---- neutral hadron multiplicity -------
     int nhm_;
     //---- photon multiplicity ---------------
     int phm_;
     //---- electron multiplicity -------------
     int elm_;
     //---- muon multiplicity -----------------
     int mum_;
     //---- number of PF candidates -----------
     int ncand_;
     // --- charged multiplicity ------
     int cm_;
     //---- fraction of track pt NOT coming from the signal vertex, removed by chs ---
     float betaPrime_;

     // Juska:
     int mpuTrk_; // PU-tracks in jet
     int mlvTrk_; // lead vertex tracks in jet
     int mjtTrk_; // all tracks in jet (also unassociated)
     float hof_; // Hadronic Outer energy fraction


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

     vector<double> z_;
     vector<double> kT_;
     vector<double> theta_;

     vector<double> z_charged_;
     vector<double> kT_charged_;
     vector<double> theta_charged_;
 
//     vector<double> purity_;
     float jetphi_CA_;
     float jetphi_CA_charged_;
     float pujid_;
};
#endif
