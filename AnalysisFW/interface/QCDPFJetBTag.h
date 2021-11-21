//Author K. Kousouris
//Modified by: S. Ganguly

#ifndef QCDPFJetBTag_h
#define QCDPFJetBTag_h
#include "LundPlane_LLR/AnalysisFW/interface/QCDJet.h"
#include "TLorentzVector.h"
class QCDPFJetBTag : public QCDJet {
  public:
    //------------ Constructor ------------------------------
    QCDPFJetBTag() {}
    //------------ Destructor -------------------------------
    ~QCDPFJetBTag() {}
    //------------ Set methods ------------------------------

    void setQGTagger (float fQGL, float fQGAx2, int fQGMul, float fQGPtD) { QGL_ = fQGL; QGAx2_ = fQGAx2; QGMul_ = fQGMul; QGPtD_ = fQGPtD; }

    float pfCombinedCvsL_, pfCombinedCvsB_;
    float pfDeepCSVb_, pfDeepCSVc_, pfDeepCSVl_, pfDeepCSVbb_;
    float pfBTag_JetProb_;
    float pfBTag_CombInclSecVtxV2_;
    float pfBTag_CombMVAV2_; 

    float QGL_;
    float QGAx2_;
    int   QGMul_;
    float QGPtD_;

    void setFlavour(int fpartonflavour, int fhadronflavour, int fpartonflavourPhysicsDef) { partonFlavour_ = fpartonflavour; hadronFlavour_ = fhadronflavour; partonFlavourPhysicsDef_ = fpartonflavourPhysicsDef;}

    int partonFlavour_;
    int partonFlavourPhysicsDef_;
    int hadronFlavour_;

    void setJetAngularities (float fLHA, float fWidth, int fThrust, float fPtD, int fMult) { LHA_ = fLHA; Width_ = fWidth; Thrust_ = fThrust; PtD_ = fPtD; Mult_ = fMult;}
// these should be the angularities of SMP-20-010, arxiv.org/abs/2109.03340
//
    float LHA_;
    float Width_;
    float Thrust_;
    float PtD_;
    int   Mult_;

};
#endif
