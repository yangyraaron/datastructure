##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cda
ConfigurationName      :=Debug
WorkspacePath          := "/home/wisedulab2/projects/c/cda"
ProjectPath            := "/home/wisedulab2/projects/c/cda"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=wisedulab2
Date                   :=08/08/2013
CodeLitePath           :="/home/wisedulab2/.codelite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
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
ObjectsFileList        :="cda.txt"
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
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/cda$(ObjectSuffix) $(IntermediateDirectory)/list$(ObjectSuffix) $(IntermediateDirectory)/lklist$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/stk$(ObjectSuffix) $(IntermediateDirectory)/mgsort$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/cda$(ObjectSuffix): cda.c $(IntermediateDirectory)/cda$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/cda.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cda$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cda$(DependSuffix): cda.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cda$(ObjectSuffix) -MF$(IntermediateDirectory)/cda$(DependSuffix) -MM "cda.c"

$(IntermediateDirectory)/cda$(PreprocessSuffix): cda.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cda$(PreprocessSuffix) "cda.c"

$(IntermediateDirectory)/list$(ObjectSuffix): list.c $(IntermediateDirectory)/list$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list$(DependSuffix): list.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list$(ObjectSuffix) -MF$(IntermediateDirectory)/list$(DependSuffix) -MM "list.c"

$(IntermediateDirectory)/list$(PreprocessSuffix): list.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list$(PreprocessSuffix) "list.c"

$(IntermediateDirectory)/lklist$(ObjectSuffix): lklist.c $(IntermediateDirectory)/lklist$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/lklist.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lklist$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lklist$(DependSuffix): lklist.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lklist$(ObjectSuffix) -MF$(IntermediateDirectory)/lklist$(DependSuffix) -MM "lklist.c"

$(IntermediateDirectory)/lklist$(PreprocessSuffix): lklist.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lklist$(PreprocessSuffix) "lklist.c"

$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/stk$(ObjectSuffix): stk.c $(IntermediateDirectory)/stk$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/stk.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stk$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stk$(DependSuffix): stk.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stk$(ObjectSuffix) -MF$(IntermediateDirectory)/stk$(DependSuffix) -MM "stk.c"

$(IntermediateDirectory)/stk$(PreprocessSuffix): stk.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stk$(PreprocessSuffix) "stk.c"

$(IntermediateDirectory)/mgsort$(ObjectSuffix): mgsort.c $(IntermediateDirectory)/mgsort$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/wisedulab2/projects/c/cda/mgsort.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mgsort$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mgsort$(DependSuffix): mgsort.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mgsort$(ObjectSuffix) -MF$(IntermediateDirectory)/mgsort$(DependSuffix) -MM "mgsort.c"

$(IntermediateDirectory)/mgsort$(PreprocessSuffix): mgsort.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mgsort$(PreprocessSuffix) "mgsort.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/cda$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/cda$(DependSuffix)
	$(RM) $(IntermediateDirectory)/cda$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/list$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/list$(DependSuffix)
	$(RM) $(IntermediateDirectory)/list$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/lklist$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/lklist$(DependSuffix)
	$(RM) $(IntermediateDirectory)/lklist$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/stk$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stk$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stk$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mgsort$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mgsort$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mgsort$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/cda"


