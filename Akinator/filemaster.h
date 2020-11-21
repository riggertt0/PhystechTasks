//Version 0.5

struct Lines {
    //The text of lines
    char** line;
    //Number of lines
    size_t numberOfLines;
};

size_t GetNumberOfBytesOfFile (const char *fileName);

char* ReadTextFromFile (const char *fileName);

bool WriteTextInFile (const char *fileName, char* text);

Lines* GetLinesFromText (char* text);

size_t GetNumberOfSymbol (const char *text, char symbol);

bool FilesContainSameText (const char *first, const char *second);
