#include "usuario.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int nMaxContas, contasCadastradas = 0;
    scanf("%d", &nMaxContas);
    tConta contas[nMaxContas];
    tUsuario usuarios[nMaxContas];
    
    while(1)
    {
        int operacao;
        scanf("%d", &operacao);
        if(operacao == 0)
        {
            break;
        }
        if(contasCadastradas == nMaxContas)
        {
            break;

        }else if (operacao == 1)
        {
            if (contasCadastradas == 0)
                printf("Não há contas cadastradas ainda");
            else 
            {
                int numConta;
                float valor;
                scanf("%d %f", &numConta, &valor);
                for(int i = 0; i<contasCadastradas; i++)
                {
                    if(VerificaConta(contas[i], numConta))
                    {
                        contas[i] = SaqueConta(contas[i], valor);
                        break;
                    }
                }
            }
        }else if (operacao == 2)
        {
            if (contasCadastradas == 0)
                printf("Não há contas cadastradas aida");
            else 
            {
                int numConta;
                float valor;
                scanf("%d %f", &numConta, &valor);
                for(int i = 0; i < contasCadastradas; i++)
                {
                    if(VerificaConta(contas[i], numConta))
                    {
                        contas[i] = DepositoConta(contas[i], valor);
                        break;
                    }
                }
            }
        }else if (operacao == 3)
        {
            tConta c;
            tUsuario u;
            scanf("%s %s %d", u.nome, u.cpf, &c.numero);
            u = CriaUsuario(u.nome, u.cpf);
            c = CriaConta(c.numero, u);


            contas[contasCadastradas] = c;
            usuarios[contasCadastradas] = u;
            contasCadastradas++;
        }else if (operacao == 4)
        {
            for(int i; i<contasCadastradas; i++)
            {
                ImprimeConta(contas[i]);
                ImprimeUsuario(usuarios[i]);
            }
        }
        
    }
    return 0;
}
