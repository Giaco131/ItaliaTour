##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ItaliaTour
ConfigurationName      :=Debug
WorkspacePath          :=C:/ItaliaTour
ProjectPath            :=C:/ItaliaTour/ItaliaTour
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=àò-àòàòòòòòòòò
Date                   :=17/06/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ItaliaTour.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/funzioniGenerali.cpp$(ObjectSuffix) $(IntermediateDirectory)/grafica.cpp$(ObjectSuffix) $(IntermediateDirectory)/letturaFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/sqlite3.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/funzioniGenerali.cpp$(ObjectSuffix): funzioniGenerali.cpp $(IntermediateDirectory)/funzioniGenerali.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ItaliaTour/ItaliaTour/funzioniGenerali.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/funzioniGenerali.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/funzioniGenerali.cpp$(DependSuffix): funzioniGenerali.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/funzioniGenerali.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/funzioniGenerali.cpp$(DependSuffix) -MM "funzioniGenerali.cpp"

$(IntermediateDirectory)/funzioniGenerali.cpp$(PreprocessSuffix): funzioniGenerali.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/funzioniGenerali.cpp$(PreprocessSuffix) "funzioniGenerali.cpp"

$(IntermediateDirectory)/grafica.cpp$(ObjectSuffix): grafica.cpp $(IntermediateDirectory)/grafica.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ItaliaTour/ItaliaTour/grafica.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grafica.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grafica.cpp$(DependSuffix): grafica.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grafica.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/grafica.cpp$(DependSuffix) -MM "grafica.cpp"

$(IntermediateDirectory)/grafica.cpp$(PreprocessSuffix): grafica.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grafica.cpp$(PreprocessSuffix) "grafica.cpp"

$(IntermediateDirectory)/letturaFile.cpp$(ObjectSuffix): letturaFile.cpp $(IntermediateDirectory)/letturaFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ItaliaTour/ItaliaTour/letturaFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/letturaFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/letturaFile.cpp$(DependSuffix): letturaFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/letturaFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/letturaFile.cpp$(DependSuffix) -MM "letturaFile.cpp"

$(IntermediateDirectory)/letturaFile.cpp$(PreprocessSuffix): letturaFile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/letturaFile.cpp$(PreprocessSuffix) "letturaFile.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ItaliaTour/ItaliaTour/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/sqlite3.c$(ObjectSuffix): sqlite3.c $(IntermediateDirectory)/sqlite3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/ItaliaTour/ItaliaTour/sqlite3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sqlite3.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sqlite3.c$(DependSuffix): sqlite3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sqlite3.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sqlite3.c$(DependSuffix) -MM "sqlite3.c"

$(IntermediateDirectory)/sqlite3.c$(PreprocessSuffix): sqlite3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sqlite3.c$(PreprocessSuffix) "sqlite3.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


