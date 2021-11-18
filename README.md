# LundPlane_LLR

Analysis framework for Lund jet plane Run-2 analysis.


Starting from the SMPJ inclusive jet ntuplizer ( https://github.com/errai-/SMPJ & https://twiki.cern.ch/twiki/bin/viewauth/CMS/InclusiveJetsLegacy )



Instructions for quick setup:


LCG_lib_name=lib64

LCG_arch=x86_64

export SCRAM_ARCH=slc7_amd64_gcc700

export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch

source $VO_CMS_SW_DIR/cmsset_default.sh

source $VO_CMS_SW_DIR/crab3/crab.sh

scram p -n C10620p1 CMSSW CMSSW_10_6_20_patch1

cd C10620p1/src

cmsenv

git cms-init

git clone https://github.com/Cristian-Baldenegro/LundPlane_LLR

scram b -j

cd SMPJ/AnalysisFW/python/

there are a few macros in SMPJ/AnalysisFW/python/macros to start producing histograms
