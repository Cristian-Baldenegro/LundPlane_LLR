# LundPlane_LLR

miniAOD analysis framework for Lund jet plane Run-2 analysis. (starting from the SMPJ inclusive jet ntuplizer: https://github.com/errai-/SMPJ & https://twiki.cern.ch/twiki/bin/viewauth/CMS/InclusiveJetsLegacy )



Instructions for quick setup:


LCG_lib_name=lib64<br/>
LCG_arch=x86_64<br/>
export SCRAM_ARCH=slc7_amd64_gcc700<br/>
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch<br/>
source $VO_CMS_SW_DIR/cmsset_default.sh<br/>
source $VO_CMS_SW_DIR/crab3/crab.sh<br/>
scram p -n C10620p1 CMSSW CMSSW_10_6_20_patch1<br/>
cd C10620p1/src<br/>
cmsenv<br/>
git cms-init<br/>
git clone https://github.com/Cristian-Baldenegro/LundPlane_LLR <br/>
scram b -j<br/>
cd SMPJ/AnalysisFW/python/ <br/>

If you want to run over data for anti-kT R = 0.4 jets in 2016, you do:

cmsRun cfg/ak416.py

it fetches datafiles from filelists.py

The main Ntuplizer is in SMPJ/AnalysisFW/plugins/ProcessedTreeProducerBTag.cc . This is where the angularities are being calculated at the moment.
We could create additional tasks for the Lund plane task under SMPJ/AnalysisFW/plugins/

there are a few macros in SMPJ/AnalysisFW/python/macros to start producing histograms <br/>
