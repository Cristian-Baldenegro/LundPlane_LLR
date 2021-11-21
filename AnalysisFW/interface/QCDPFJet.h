//Author K. Kousouris
//Modified by: S. Ganguly

#ifndef QCDPFJet_h
#define QCDPFJet_h
#include "LundPlane_LLR/AnalysisFW/interface/QCDJet.h"
#include "LundPlane_LLR/AnalysisFW/interface/QCDPFJetBTag.h"
#include "TLorentzVector.h"
class QCDPFJet : public QCDPFJetBTag {
   public:
     //------------ Constructor ------------------------------
     QCDPFJet() {chf_=0;nhf_=0;nemf_=0;cemf_=0;muf_=0;chm_=0;nhm_=0;phm_=0;elm_=0;mum_=0,cm_=0; lha_=-1; width_=-1; thrust_= -1;}
     //------------ Destructor -------------------------------
     ~QCDPFJet() {}
     //------------ Set methods ------------------------------
     void setFrac(float fchf, float fnhf, float fnemf, float fcemf, float fmuf)  {chf_ = fchf; nhf_ = fnhf; nemf_ = fnemf; cemf_ = fcemf; muf_ = fmuf;}
     void setLHA(float flha){ lha_ = flha;}
     void setWidth(float fwidth){ width_ = fwidth;}
     void setThrust(float fthrust){ thrust_ = fthrust;}
     void setMulti(int fncand, int fchm, int fnhm, int fphm, int felm, int fmum, int fcm) {ncand_ = fncand; chm_ = fchm; nhm_ = fnhm; phm_ = fphm; elm_ = felm; mum_ = fmum; cm_ = fcm; }
     void setBetaPrime(float fbetaPrime) {betaPrime_ = fbetaPrime;}
     void setHFFrac(float fhf_hf, float fhf_phf) {hf_hf_ = fhf_hf; hf_phf_ = fhf_phf;}
     void setHFMulti(int fhf_hm, int fhf_phm) {hf_hm_ = fhf_hm; hf_phm_ = fhf_phm;}
     void setVtxInfo(int mpuTrk, int mlvTrk, int mjtTrk) { mpuTrk_ = mpuTrk; mlvTrk_ = mlvTrk; mjtTrk_ = mjtTrk;} // Juska
     void setHO(float hof) {hof_ = hof;} // Juska
     void SetPUJetId(float pujid) { pujid_ = pujid; }

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

     float pujid_;
};
#endif
