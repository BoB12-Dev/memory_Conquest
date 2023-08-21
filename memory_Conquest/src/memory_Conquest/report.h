
struct VBS : public core::IFormatterObject
{
	std::tstring strTargetID;
	std::tstring strParentID;
	std::tstring strAbsolutePath;
	std::tstring strFileName;
	int intFileSize;
	std::tstring strFileEXT;
	std::tstring strMD5;
	std::tstring strSHA1;
	std::tstring strSHA256;
	std::tstring strHAS160;
	std::tstring strFileHeaderDump;
	int intIsExtractedFile;
	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("TargetID"), strTargetID)
			+ core::sPair(TEXT("ParentID"), strParentID)
			+ core::sPair(TEXT("AbsolutePath"), strAbsolutePath)
			+ core::sPair(TEXT("FileName"), strFileName)
			+ core::sPair(TEXT("FileSize"), intFileSize)
			+ core::sPair(TEXT("FileEXT"), strFileEXT)
			+ core::sPair(TEXT("MD5"), strMD5)
			+ core::sPair(TEXT("SHA1"), strSHA1)
			+ core::sPair(TEXT("SHA256"), strSHA256)
			+ core::sPair(TEXT("HAS160"), strHAS160)
			+ core::sPair(TEXT("FileHeaderDump"), strFileHeaderDump)
			+ core::sPair(TEXT("IsExtractedFile"), intIsExtractedFile)
			;
	}
};

struct ST_TARGETFILE : public core::IFormatterObject
{
	VBS vbs;
	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("1777336a2b446fbca3172d309884ee65e4e6c0655b3ce1a38301a9c6d61f7195.vbs"), vbs)
			;
	}
};

struct ST_SUMMARY : public core::IFormatterObject
{

	std::tstring strResult;
	std::tstring strDetectName;
	std::tstring strEngineName;
	std::tstring strEngineVersion;
	int intSeverity;
	std::tstring strSampleName;
	std::tstring strSampleExt;
	int intCurLoopCount;
	int intMaxLoopCount;
	double doubleTotalElapsedTime;

	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("Result"), strResult)
			+ core::sPair(TEXT("DetectName"), strDetectName)
			+ core::sPair(TEXT("EngineName"), strEngineName)
			+ core::sPair(TEXT("EngineVersion"), strEngineVersion)
			+ core::sPair(TEXT("Severity"), intSeverity)
			+ core::sPair(TEXT("SampleName"), strSampleName)
			+ core::sPair(TEXT("SampleExt"), strSampleExt)
			+ core::sPair(TEXT("CurLoopCount"), intCurLoopCount)
			+ core::sPair(TEXT("MaxLoopCount"), intMaxLoopCount)
			+ core::sPair(TEXT("TotalElapsedTime"), doubleTotalElapsedTime)
			;
	}

};

struct ST_TARGETS : public core::IFormatterObject
{
	ST_TARGETFILE TargetFile;
	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("TargetFile"), TargetFile)
			;
	}
};

struct ST_EVENT : public core::IFormatterObject
{
	std::tstring EngineName;
	std::tstring EngineVersion;
	std::tstring TargetID;
	std::tstring PlatformID;
	std::tstring Name;
	std::tstring AnalysisCode;
	int Severity;
	std::tstring Desc;

	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("EngineName"), EngineName)
			+ core::sPair(TEXT("EngineVersion"), EngineVersion)
			+ core::sPair(TEXT("TargetID"), TargetID)
			+ core::sPair(TEXT("PlatformID"), PlatformID)
			+ core::sPair(TEXT("Name"), Name)
			+ core::sPair(TEXT("AnalysisCode"), AnalysisCode)
			+ core::sPair(TEXT("Severity"), Severity)
			+ core::sPair(TEXT("Desc"), Desc)
			;
	}
};


struct ST_DETECTION : public core::IFormatterObject
{
	std::vector<ST_EVENT> events;
	void OnSync(core::IFormatter& formatter)
	{
		formatter + core::sPair(TEXT("Event"), events);	
	}
};

struct ST_REPORT : public core::IFormatterObject
{

	ST_SUMMARY Summary;
	ST_TARGETS Targets;
	ST_DETECTION Detection;
	void OnSync(core::IFormatter& formatter)
	{
		formatter
			+ core::sPair(TEXT("Summary"), Summary)
			+ core::sPair(TEXT("Targets"), Targets)
			+ core::sPair(TEXT("Detection"), Detection)
			;
	}
};
