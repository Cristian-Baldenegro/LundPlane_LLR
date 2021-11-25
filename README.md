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
cd LundPlane_LLR/AnalysisFW/python/ <br/>

Then, you create the directory cfg_check<br/>

mkdir cfg_check

And create the configuration files for MC and data with <br/>

python cfgProducer.py

If you want to run over data for anti-kT R = 0.4 jets in 2016, you do:

cmsRun cfg_check/ak416.py

it fetches datafiles from filelists.py

The main Ntuplizer is in LundPlane_LLR/AnalysisFW/plugins/ProcessedTreeProducerBTag.cc . This is where the angularities are being calculated at the moment.
We could create additional tasks for the Lund plane task under LundPlane_LLR/AnalysisFW/plugins/

there are a few macros in LundPlane_LLR/AnalysisFW/python/macros to start producing histograms.
For example, to store basic histograms, apply high-level cuts, etc, you can run:<br/>

root -l ProcessedTree_data.C<br/>
ProcessedTree_data t; t.Loop()<br/>

The output file "output.root" contains histograms with basic dijet distributions and angularities. The input file is fetched in ProcessedTree_data.h.

Once you make sure that you are able to run over single miniAOD files, we can move on to executing crab jobs. To run the crab jobs, make sure you have the permissions to write in DPM. The main files are crabConfig.py and serialrun.sh <br/>

The best way to systematically submit jobs is via serialrun.sh. There, you can specify the year, the type of jets (ak4 jets), and the era (e.g., era B, C, D, E, ...) when running over data. For MC, there's an option for iterating over the different pThat or HT bins that is commented out.<br/>

After properly modifying serialrun.sh to your needs, do <br/>

bash serialrun.sh<br/>

This will run crabConfig.py with the settings of your choice. The crab-related files are created under runs_dt or runs_mc for data or MC, respectively.
