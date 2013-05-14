#ifndef informationH
#define informationH

class Information
{
public:
    Information(unsigned char NumberOfGroups, unsigned char NumberOfTeachers,
                unsigned char NumberOfSubjects);
protected:
    unsigned char numberOfGroups;
    unsigned char numberOfTeachers;
    unsigned char numberOfSubjects;
    char** groups;
    char** teachers;
    char** subjects;
}
#endif
