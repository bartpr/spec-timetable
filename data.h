#ifndef dataH
#define dataH
class Data
{
public:
    Data(unsigned char numberOfGroups);
    ~Data();

protected:
    unsigned char numerOfGroups;
    struct Lesson
    {
        unsigned char group, teacher, subject; //unikalne identyfikatory grupy, nauczyciela, przedmiotu
    } *tab; //wszystkie informacje o konkretnym genie

    /*struct Group
    {
        unsigned char numberOfSubjects;
        char** table;
    } *groups;
    */
};


#endif
