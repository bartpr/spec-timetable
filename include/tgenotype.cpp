
	void tgenotype::setParameters(uint16_t nGenes, uint8_t nTerms, uint8_t nRooms)
    {
        this->numberOfGenes = nGenes;
        this->numberOfTerms = nTerms;
        this->numberOfRooms = nRooms;
    }

    void tgenotype::setMark(double mark)
    {
     this->mark = mark;
    }

    void tgenotype::setPenalty(bool penalty)
    {
     this->penalty = penalty;
    }
	
	//Dodanie friend do Genotype
	void *prepareGenotype(Genotype *geno, unsigned int *sPacket = NULL)
	{
        //Pobranie tablicy genów genotypu
        //Geny muszą zostac osobno przetworzone do formy bajtowej tablicy
        //Ponieważ sam genotyp zawiera do nich tylko wskaźnik
        //Wiec nie zawieraja sie w samym nim
        //Zostana wysłane zaraz po strukturze transportowej tgenotype
        //Która przechowuje informacje dla genotypu
        //TGENOTYPE | CHAR[] GENES
        Gene **g = geno->genes;
        size_t nGenes = geno->numberOfGenes;



        size_t nGenesBufor = sizeof(Gene)*nGenes + 1; //Wielkosc bufora char[] dla genów
        char *genesBufor = new char[nGenesBufor]; //bufor dla genów
        memset(genesBufor,'\0',nGenesBufor);      //wyczyszczenie bufora

        //skopiowanie genów do bufora
        for(uint8_t i = 0; i < nGenes; i++)
        {
                Gene *gene = g[i];
                //void *strGene = prepareGene(gene);
                memcpy(genesBufor+(i*sizeof(Gene)),gene,sizeof(Gene));
        }

        //stworzenie struktury transportowej dla genotypu
        struct tgenotype *tgeno = new tgenotype;
        tgeno->numberOfGenes = geno->numberOfGenes;
        tgeno->numberOfTerms = geno->numberOfTerms;
        tgeno->numberOfRooms = geno->numberOfRooms;
        tgeno->mark = geno->mark;
        tgeno->penalty = geno->penalty;



        //inicjalizacja bufora ogólnago
        size_t bSize = nGenesBufor + sizeof(tgenotype);
        char *bufor = new char[bSize];
        memset(bufor,'\0',bSize);

        //skopiowanie do bufora struktury transportowej
        memcpy(bufor,tgeno,sizeof(tgenotype));
        //skopiowanie do bufora genów
        memcpy(bufor+sizeof(tgenotype),genesBufor,nGenesBufor);

        //usunięcie buforów roboczych
        delete genesBufor;
        delete tgeno;
        //zwrócenie głównego bufora


        if(sPacket != NULL)
        {
         *sPacket = bSize;
        }

        return bufor;

	}