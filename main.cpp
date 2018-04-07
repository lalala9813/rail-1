#include <iostream>

using namespace std;

string alfabeto = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
    'p','q','r','s','t','u','v','w','x','y','z',' '};

void desencriptado(string cripMessage)
{
    int clave;
    cout << "********************************************************************************\n";
    cout << "Dame clave para desencriptar -> ";
    cin >> clave;

    //Creando la matriz
    char matrix[clave][cripMessage.length()];

    for(int i = 0; i < clave; i++)
    {
        for(int j = 0; j < cripMessage.length(); j++)
        {
            matrix[i][j] = '.';
        }
    }
    //Mensaje pre-encriptado
    cout << "\n" << "Su mensaje pre-desencriptado es -> " << cripMessage << "\n\n";

    //Llenando matriz
    int fil = 0;
    int aux = clave;
    bool ok = false;

    for(int col = 0; col < cripMessage.length(); col++)
    {
        if(ok == false)
        {
            matrix[fil][col] = cripMessage[col];
            //cout << fil << " , " << col << endl;
            fil++;
            if(fil == aux)
            {
                ok = true;
                fil--;
            }
        }
        else
        {
            fil--;
            //cout << fil << " , " << col << endl;
            matrix[fil][col] = cripMessage[col];
            if(fil == 0)
            {
                ok = false;
                fil = 1;
            }
            //cout << fil << " * " << col << endl;
        }
    }

    int alfTam = alfabeto.size() - 1;
    string finalDes = "";

    for(int i = 0; i < cripMessage.size(); i++)
    {
        for(int j = 0; j < alfTam; j++)
        {
            if(cripMessage[i] == alfabeto[j])
            {
                if(cripMessage[i] == ' ')
                {
                    finalDes += alfabeto[0];
                    cout << "Lo hice" ;
                }
                else
                {
                    finalDes += alfabeto[alfTam - j];
                }
            }
        }
    }

    cout << "Su mensaje descifrado es -> " << finalDes;
    //Imprimiendo
    /*for(int i = 0; i < clave; i++)
    {
        for(int j = 0; j < cripMessage.length(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }*/
}

void encriptado(string msm)
{
    int alfTam = alfabeto.size() - 1;
    string cripMessage = "";
    string finalMsm = "";

    for(int i = 0; i < msm.size(); i++)
    {
        for(int j = 0; j < alfTam; j++)
        {
            if(msm[i] == alfabeto[j])
            {
                cripMessage += alfabeto[alfTam - j];
            }
        }
    }

    //pidiendo clave
    int clave;
    cout << "Dame clave para encriptar -> ";
    cin >> clave;

    //Creando la matriz
    char matrix[clave][cripMessage.length()];

    for(int i = 0; i < clave; i++)
    {
        for(int j = 0; j < cripMessage.length(); j++)
        {
            matrix[i][j] = '.';
        }
    }
    //Mensaje pre-encriptado
    cout << "\n" << "Su mensaje pre-encriptado es -> " << cripMessage << "\n\n";

    //Llenando matriz
    int fil = 0;
    int aux = clave;
    bool ok = false;

    for(int col = 0; col < cripMessage.length(); col++)
    {
        if(ok == false)
        {
            matrix[fil][col] = cripMessage[col];
            //cout << fil << " , " << col << endl;
            fil++;
            if(fil == aux)
            {
                ok = true;
                fil--;
            }
        }
        else
        {
            fil--;
            //cout << fil << " , " << col << endl;
            matrix[fil][col] = cripMessage[col];
            if(fil == 0)
            {
                ok = false;
                fil = 1;
            }
            //cout << fil << " * " << col << endl;
        }
    }

    //Imprimiendo
    for(int i = 0; i < clave; i++)
    {
        for(int j = 0; j < cripMessage.length(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    //Mensaje cifrado final
    for(int i = 0; i < clave; i++)
    {
        for(int j = 0; j < cripMessage.length(); j++)
        {
            if(matrix[i][j] != '.')
            {
                finalMsm += matrix[i][j];
            }
        }
    }

    cout << "\nSu mensaje encriptado FINAL -> " << finalMsm << endl;

    desencriptado(cripMessage);
    //return cripMessage;
}

void desencriptado()
{

}

int main()
{
    string msm;
    cout << "Deme su mensaje -> ";
    getline(cin,msm);

    encriptado(msm);

    return 0;
}
