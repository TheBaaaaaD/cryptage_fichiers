#include "cryptage.hpp"

int main()
{
    FILE *fichier;
    FILE *crypter;
    
    unsigned char contenu[12];
    unsigned char hash[12];
    bitset<8> test[12];
    bitset<8> clef{0xAB};
    //char test = 'A';
    bitset<8> caractere;
    bitset<8> crypt;
    
    fichier = fopen("text.txt","r");
    crypter = fopen("crypter.txt", "w+");
    
    if(fichier && crypter)
    {
        cout<<"fichiers ouvert"<<endl;
        fread(contenu, sizeof(unsigned char),12,fichier);
        
//penser à récupérer la taille du tableau que ça marche tout le temps
        for (int i = 0; i < 12; i++) {
            //cout<<contenu[i];
            caractere = conversion(contenu[i]);
            crypt = caractere ^ clef;
            cout<<crypt<<endl;
            test[i] = crypt;
        }
        
        cout<<""<<endl;
        
        fwrite(hash, sizeof(unsigned char),12, crypter);
        /*
        for (int i = 0; i < 13; i++) {
            cout<<hash[i];
        }
        */
        for (int i = 0; i < 12; i++) {
            //cout<<contenu[i];
            crypt = test[i] ^ clef;
            cout<<crypt<<endl;
        }
        cout<<""<<endl;
        
        //cout<<clef<<endl;
        
        
    }
    else
    {
        cout<<"erreur lors de l'ouverture du fichier"<<endl;
    }
    fclose(fichier);
    fclose(crypter);

    return 0;
}
