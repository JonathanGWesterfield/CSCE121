##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab20
ConfigurationName      :=Debug
WorkspacePath          :="/Users/JonathanWesterfield/Documents/CSCE 121/Class C++"
ProjectPath            :="/Users/JonathanWesterfield/Documents/CSCE 121/Lab20"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jonathan G. Westerfield
Date                   :=27/09/2016
CodeLitePath           :="/Users/JonathanWesterfield/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
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
ObjectsFileList        :="Lab20.txt"
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/JonathanWesterfield/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(ObjectSuffix): pass-by-ref-const-ref-student.cpp $(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/JonathanWesterfield/Documents/CSCE 121/Lab20/pass-by-ref-const-ref-student.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(DependSuffix): pass-by-ref-const-ref-student.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(DependSuffix) -MM pass-by-ref-const-ref-student.cpp

$(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(PreprocessSuffix): pass-by-ref-const-ref-student.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pass-by-ref-const-ref-student.cpp$(PreprocessSuffix)pass-by-ref-const-ref-student.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


