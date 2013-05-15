#ifndef dataH
#define dataH
class Data
{
public:
    Data(unsigned char numberOfGroups);
    ~Data();

protected:
    unsigned char numerOfGroups;
    struct Group
    {
        unsigned char numberOfSubjects;
        char** table;
    } *groups;
};


#endif
