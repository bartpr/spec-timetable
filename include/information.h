#ifndef informationH
#define informationH
/*
    Potrzebne do tłumaczenia identyfikatorów grup, nauczycieli i przedmiotów na nazwy.
    Niepotrzebne do działania częsci własciwej programu.
    Potrzebne tylko do interfejsu wyjscia i wejscia.
    Istnieje tylko 1 obiekt takiej klasy i znajduje się na stacji bazowej.
*/
class Information
{
public:
    Information(unsigned char NumberOfGroups, unsigned char NumberOfTeachers,
                unsigned char NumberOfSubjects);
				
	
protected:
	friend void* prepareInformation(Information *inf);
    unsigned char numberOfGroups;
    unsigned char numberOfTeachers;
    unsigned char numberOfSubjects;
    char** groups;
    char** teachers;
    char** subjects;
};
#endif
