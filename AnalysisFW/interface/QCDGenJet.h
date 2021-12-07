//Authors: Lund plane LLR team

#ifndef QCDGenJet_h
#define QCDGenJet_h
#include "LundPlane_LLR/AnalysisFW/interface/QCDJet.h"
#include "LundPlane_LLR/AnalysisFW/interface/QCDPFJetBTag.h"
#include "TLorentzVector.h"
class QCDGenJet : public QCDPFJetBTag {
   public:
     //------------ Constructor ------------------------------
     QCDGenJet() {lha_=-1; width_=-1; thrust_= -1; ptD2_ = -1; multiplicity_ = -1; lha_charged_=-1; width_charged_=-1; thrust_charged_= -1; ptD2_charged_ = -1; multiplicity_charged_ = -1;}
     //------------ Destructor -------------------------------
     ~QCDGenJet() {}
     //------------ Set methods ------------------------------
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

   private:
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

};
#endif
