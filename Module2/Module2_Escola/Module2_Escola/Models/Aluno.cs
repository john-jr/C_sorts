using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Module2_Escola.Models
{
    class Aluno
    {
        private int RA;
        private string nomeCompleto;
        private Ano serie;

        public Aluno()
        {
            RA = 0;
            nomeCompleto = null;
            serie = 0;
        }

        internal enum Ano
        {
            PrimeiraSerie = 1,
            SegundaSerie = 2,
            TerceiraSerie = 3,
            QuartaSerie = 4,
            QuintaSerie = 5,
            SextaSerie = 6,
            SetimaSerie = 7,
            OitavaSerie = 8,
            PrimeiroAnoMedio = 9,
            SegundoAnoMedio = 10,
            TerceiroAnoMedio = 11
        }

    }
}
