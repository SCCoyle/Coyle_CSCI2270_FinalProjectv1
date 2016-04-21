##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FinalProject
ConfigurationName      :=Debug
WorkspacePath          := "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject"
ProjectPath            := "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Samuel Coyle
Date                   :=21/04/16
CodeLitePath           :="/home/scoyle/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="FinalProject.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/market.cpp$(ObjectSuffix) $(IntermediateDirectory)/Final.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/market.cpp$(ObjectSuffix): market.cpp $(IntermediateDirectory)/market.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject/market.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/market.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/market.cpp$(DependSuffix): market.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/market.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/market.cpp$(DependSuffix) -MM "market.cpp"

$(IntermediateDirectory)/market.cpp$(PreprocessSuffix): market.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/market.cpp$(PreprocessSuffix) "market.cpp"

$(IntermediateDirectory)/Final.cpp$(ObjectSuffix): Final.cpp $(IntermediateDirectory)/Final.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject/Final.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Final.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Final.cpp$(DependSuffix): Final.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Final.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Final.cpp$(DependSuffix) -MM "Final.cpp"

$(IntermediateDirectory)/Final.cpp$(PreprocessSuffix): Final.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Final.cpp$(PreprocessSuffix) "Final.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


