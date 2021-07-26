using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projeto_Escola.Model
{
     class FuncoesFuncionarios
    {
        private static List<Funcionario> lista_Funcionarios;

        public FuncoesFuncionarios()
        {
            lista_Funcionarios = new List<Funcionario>()
            {
                new Funcionario{Id= 123, Nome="Rodrigo", Cpf="455.435.354-04", Salario=500.00}
            }
            ;
        }


        public List<Funcionario> GetAll()
        {
            return lista_Funcionarios;
        }

        public bool AddFuncionario(Funcionario novoFuncionario)
        {
            if (novoFuncionario != null) {
                if (novoFuncionario.Id != 0)
                     {
                    if (ProcurarFuncionario(novoFuncionario.Id) == null)
                    {
                        if (novoFuncionario.Cpf != null)
                        {
                            if (novoFuncionario.Nome != "")
                            {
                                if (novoFuncionario.Salario != 0)
                                {
                                    lista_Funcionarios.Add(novoFuncionario);


                                    return true;
                                }
                            }
                        }
                    }
                }
                }
            return false;
        }

        public bool AtualizarFuncionario(Funcionario atualizarThisFuncionario)
        {
            bool IsUpdated = false;
                for(int index =0; index < lista_Funcionarios.Count; index++)
            {
                if (lista_Funcionarios[index].Id == atualizarThisFuncionario.Id)
                {
                    lista_Funcionarios[index].Nome = atualizarThisFuncionario.Nome;
                    lista_Funcionarios[index].Cpf = atualizarThisFuncionario.Cpf;
                    lista_Funcionarios[index].Salario = atualizarThisFuncionario.Salario;
                    IsUpdated = true;
                    break;
                }
            }
            return IsUpdated;
        }


        public bool DeletarFuncionario(int idFuncionairo)
        {
            bool isDeleted = false;
            for (int index = 0; index < lista_Funcionarios.Count; index++) { 
                if(lista_Funcionarios[index].Id == idFuncionairo)
                {
                    lista_Funcionarios.RemoveAt(index);
                    isDeleted = true;
                    break;
                }
            }

                return isDeleted;
        }

        public Funcionario ProcurarFuncionario(int idFuncionario)
        {
            return lista_Funcionarios.FirstOrDefault(e => e.Id == idFuncionario);
        }


    }
}
