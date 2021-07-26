using Module2_Escola.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace Module2_Escola.ViewModels
{
     internal class FuncionarioViewModel
    {
        public FuncionarioViewModel()
        {
            _funcionario = new Funcionario("Rodrigo");
        }

        private Funcionario _funcionario;
        public Funcionario funcionario
        {
            get
            {
                return funcionario;
            }
        }

        public void SalvarModificacoes()
        {
            Debug.Assert(false, String.Format("{0} foi atualizado.", funcionario.Nome));
        }

    }
}
