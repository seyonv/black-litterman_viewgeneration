MATLAB="/Applications/MATLAB_R2013a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/User/.matlab/R2013a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for hlblacklitterman" > hlblacklitterman_mex.mki
echo "CC=$CC" >> hlblacklitterman_mex.mki
echo "CFLAGS=$CFLAGS" >> hlblacklitterman_mex.mki
echo "CLIBS=$CLIBS" >> hlblacklitterman_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> hlblacklitterman_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> hlblacklitterman_mex.mki
echo "CXX=$CXX" >> hlblacklitterman_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> hlblacklitterman_mex.mki
echo "CXXLIBS=$CXXLIBS" >> hlblacklitterman_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> hlblacklitterman_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> hlblacklitterman_mex.mki
echo "LD=$LD" >> hlblacklitterman_mex.mki
echo "LDFLAGS=$LDFLAGS" >> hlblacklitterman_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> hlblacklitterman_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> hlblacklitterman_mex.mki
echo "Arch=$Arch" >> hlblacklitterman_mex.mki
echo OMPFLAGS= >> hlblacklitterman_mex.mki
echo OMPLINKFLAGS= >> hlblacklitterman_mex.mki
echo "EMC_COMPILER=" >> hlblacklitterman_mex.mki
echo "EMC_CONFIG=optim" >> hlblacklitterman_mex.mki
"/Applications/MATLAB_R2013a.app/bin/maci64/gmake" -B -f hlblacklitterman_mex.mk
