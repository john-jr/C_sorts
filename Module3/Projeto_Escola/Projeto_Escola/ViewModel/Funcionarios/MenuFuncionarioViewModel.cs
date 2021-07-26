using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ComponentModel;
using Projeto_Escola.Model;
using System.Collections.ObjectModel;
using Projeto_Escola.Commands;


namespace Projeto_Escola.ViewModel.Funcionarios
{
    public class MenuFuncionarioViewModel : INotifyPropertyChanged
    {
        #region INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }
        }
        #endregion

      

        private FuncoesFuncionarios funcoesFuncionarios;
        public MenuFuncionarioViewModel()
        {
            funcoesFuncionarios = new FuncoesFuncionarios();
            LoadData();
            NovoFuncionario = new Funcionario();
            saveCommand = new RelayCommand(Save);
            searchCommand = new RelayCommand(Search);
            updateCommand = new RelayCommand(Update);
            deleteCommand = new RelayCommand(Delete);
        }

        #region DisplayFuncionarioToUser_Operation 
        private ObservableCollection<Funcionario> lista_Funcionarios;
        public ObservableCollection<Funcionario> ListaFuncionarios
        {
            get
            {
                return lista_Funcionarios;
            }
            set
            {
                lista_Funcionarios = value;
                OnPropertyChanged("ListaFuncionarios");
            }
        }
        private void LoadData()
        {
            ListaFuncionarios = new ObservableCollection<Funcionario> (funcoesFuncionarios.GetAll());
        }
        #endregion

        private Funcionario novoFuncionario;
    
        public Funcionario NovoFuncionario {
            get
            {
                return novoFuncionario;
            }
            set
            {
                novoFuncionario = value;
                OnPropertyChanged("NovoFuncionario");
            }
        }


        private string message;
        public string Message
        {
            get
            {
                return message;
            }
            set
            {
                message = value;
                OnPropertyChanged("Message");
            }
        }

        #region saveOperation;
        private RelayCommand saveCommand;
        public RelayCommand SaveCommand{
            get
            {
                return saveCommand;
            }
        }
       
        public void Save()
        {
            try
            {
                var IsSaved = funcoesFuncionarios.AddFuncionario(NovoFuncionario);
                LoadData();
                if (IsSaved == true)
                {
                    Message = "Funcionário Salvo com sucesso";
                    NovoFuncionario = new Funcionario();
                   
                }
                else
                {
                    Message = "Error #1: Não foi possível salvar funcionário";
                }
            }catch(Exception ex)
            {
                Message = ex.Message;
            }
        }
        #endregion

        #region searchOperation;
        private RelayCommand searchCommand;
        public RelayCommand SearchCommand
        {
            get
            {
                return searchCommand;
            }
        }

        public void Search()
        {
            try
            {
                var IsFound = funcoesFuncionarios.ProcurarFuncionario(NovoFuncionario.Id);
                if(IsFound != null)
                {
                    NovoFuncionario.Id = IsFound.Id;
                    NovoFuncionario.Nome = IsFound.Nome;
                    NovoFuncionario.Cpf = IsFound.Cpf;
                    NovoFuncionario.Salario = IsFound.Salario;
                }
                else{
                    Message = "Funcionário não encontrado";
                }

            }catch(Exception ex)
            {
                Message = ex.Message;
            }

        }
        #endregion

        #region updateOperation;
        private RelayCommand updateCommand;

        public RelayCommand UpdateCommand
        {
            get
            {
                return updateCommand;
            }
        }

        public void Update()
        {
            try
            {
                var IsUpdated = funcoesFuncionarios.AtualizarFuncionario(NovoFuncionario);
                if(IsUpdated == true)
                {
                    Message = "Funcionário Atualizado";
                    LoadData();
                }
                else
                {
                    Message = "Não foi possível atualizar os dados do funcionário";
                }
            }
            catch(Exception ex)
            {
                Message = ex.Message;
            }
        }

        #endregion

        #region deleteOperation;
        private RelayCommand deleteCommand;

        public RelayCommand DeleteCommand
        {
            get
            {
                return deleteCommand;
            }
        }

        public void Delete()
        {
            try
            {
                var IsDeleted = funcoesFuncionarios.DeletarFuncionario(NovoFuncionario.Id);
                if(IsDeleted == true)
                {
                    Message = "Funcionário excluído com sucesso";
                    LoadData();
                }
                else
                {
                    Message = "Não foi possível deletar usuário";
                }
            }
            catch (Exception ex)
            {
                Message = ex.Message;
            }
        }

        #endregion
    }
}
