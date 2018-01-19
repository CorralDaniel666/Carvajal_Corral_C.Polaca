using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;
using AgentObjects;
using AxAgentObjects;
using System.Threading;

namespace WinAppManejoMSAgente
{
    public partial class frmManejoAgente : Form
    {
        private Agente mObjAgente;

        public frmManejoAgente()
        {
            InitializeComponent();
        }

        public void CargarAgente()
        {
            mObjAgente = new Agente("merlin", this, 400, 200);
            //mObjAgente = new Agente("Genie", this, 400, 200);
            //mObjAgente = new Agente("Peedy", this, 400, 200);
            //mObjAgente = new Agente("Robby", this, 400, 200);
            //mObjAgente = new Agente("Santa", this, 400, 200);
            //mObjAgente = new Agente("Max", this, 400, 200);
            
            
            mObjAgente.MostrarAgente(this);
            mObjAgente.IniciarBienvenida(this);
        }

        private void frmManejoAgente_Load(object sender, EventArgs e)
        {
            CargarAgente();
        }
    }
}
