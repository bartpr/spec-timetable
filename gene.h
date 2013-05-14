#ifndef geneH
#define geneH
class Gene
{
public:
    Gene(unsigned char term, unsigned char room);
    ~Gene();
protected:
    unsigned char term;
    unsigned char room;
};
#endif
