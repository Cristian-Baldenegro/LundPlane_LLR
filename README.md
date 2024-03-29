# LundPlane_LLR

miniAOD analysis framework for Lund jet plane Run-2 analysis. (starting from the SMPJ inclusive jet ntuplizer: https://github.com/errai-/SMPJ & https://twiki.cern.ch/twiki/bin/viewauth/CMS/InclusiveJetsLegacy )



Instructions for quick setup:

```
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
cd LundPlane_LLR/AnalysisFW/python/
```

Then, you create the directory ```cfg```

```mkdir cfg```

And create the configuration files under cfg for MC and data with the cfgProducer.py,

```
python cfgProducer.py
```

These will be the configuration files used for crabJobs eventually.
If you want to run over data for anti-kT R = 0.4 jets in 2016, you do:
<br/>
```cmsRun cfg_check/ak416.py```
<br/>

it fetches single datafiles from ```filelists.py``` and creates a root file DATA.root with the selection requirements specified in the configuration file and in ```LundPlane_LLR/AnalysisFW/plugins/ProcessedTreeProducerBTag.cc```.

The main Ntuplizer is in ```LundPlane_LLR/AnalysisFW/plugins/ProcessedTreeProducerBTag.cc``` . The jet angularities are members of the QCDPFJet.h class defined in ```LundPlane_LLR/AnalysisFW/interface/QCDPFJet.h``` This is where the angularities are being calculated at the moment.
We could create additional tasks for the Lund plane task under ```LundPlane_LLR/AnalysisFW/plugins/```.

there are a few macros in ```LundPlane_LLR/AnalysisFW/python/macros``` to start producing basic histograms.
For example, to store basic histograms, apply high-level cuts on jets, etc, you can run:<br/>

```root -l ProcessedTree_data.C ```
```ProcessedTree_data t; t.Loop()```

The output file "output.root" contains histograms with basic dijet distributions and angularities. The DATA.root input file must be fetched in ```ProcessedTree_data.h```.

Once you make sure that you are able to run over single miniAOD files, we can move on to executing crab jobs. To run the crab jobs, make sure you have the permissions to write in DPM. The main files are ```crabConfig.py``` and ```serialrun.sh``` <br/>

The best way to systematically submit jobs is via serialrun.sh. There, you can specify the year, the type of jets (ak4 jets), and the era (e.g., era B, C, D, E, ...) when running over data. For MC, there's an option for iterating over the different pThat or HT bins that is commented out.<br/>

After properly modifying ```serialrun.sh``` to your needs, do <br/>

```bash serialrun.sh``` <br/>

This will run ```crabConfig.py``` with the settings of your choice. The crab-related files are created under the ```runs_dt``` or ```runs_mc``` directories for data or MC, respectively. The ```crabConfig.py``` file will pull the configuration files from the ```cfg_check``` directory, so make sure this folder exists and has the configuration files before running crab jobs.
