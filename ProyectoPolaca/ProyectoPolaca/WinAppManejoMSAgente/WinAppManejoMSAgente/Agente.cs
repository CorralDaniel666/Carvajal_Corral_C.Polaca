using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using AgentObjects;
using AxAgentObjects;
using System.Windows.Forms;

namespace WinAppManejoMSAgente
{
    class Agente
    {
        #region Atributos de la clase
        ///<summary>
        ///Datos o variables miembro
        ///</summary>

        private AxAgent mMSAgente = new AxAgent();
        private string mNombre;
        private int mX, mY;
        private int mVoz;
        private int mCadencia;

        #endregion

        #region Propiedades
        ///<summary>
        ///Manejo de descriptores de acceso
        ///</summary>   

        public AxAgent MSAgente
        {
            get { return mMSAgente; }
            set { mMSAgente = value; }
        }

        public string Nombre
        {
            get { return mNombre; }
            set { mNombre = value; }
        }

        public int X
        {
            get { return mX; }
            set { mX = value; }
        }

        public int Y
        {
            get { return mY; }
            set { mY = value; }
        }

        public int Voz
        {
            get { return mVoz; }
            set { mVoz = value; }
        }

        public int Cadencia
        {
            get { return mCadencia; }
            set { mCadencia = value; }
        }

        #endregion

        #region Constructores de la clase
        ///<summary>
        /// Constructores
        ///</summary>

        // Constructor por defecto
        public Agente()
        {

        }

        public Agente(string nombre, Form ObjForm, int xInicial, int yFinal)
        {
            mCadencia = 100;
            mVoz = 200;
            mX = xInicial;
            mY = yFinal;
            mNombre = nombre;
            mMSAgente.BeginInit();
            ObjForm.Controls.Add(mMSAgente);
            mMSAgente.EndInit();
            mMSAgente.Characters.Load(mNombre, mNombre + ".acs");
            SeleccionarLenguaje(true);
            mMSAgente.BringToFront();
        }

        #endregion

        #region Métodos
        ///<summary>
        ///Funciones miembro
        ///</summary>  

        public void SeleccionarLenguaje(Boolean op)
        {
            if (op == true)
            {
                // Idioma Español
                mMSAgente.Characters[mNombre].LanguageID = 3082;
            }
            else
            {
                // Idioma Inglés
                mMSAgente.Characters[mNombre].LanguageID = 0x409;
            }
        }

        public void SeleccionarVoz(int tono)
        {
            mVoz = tono;
        }

        public void EstablecerCadencia(int cadencia)
        {
            mCadencia = cadencia;
        }

        public void IrPosicionInicio(Form formulario)
        {
            mMSAgente.Characters[mNombre].MoveTo(100, 100, mCadencia);
        }

        public void OcultarAgente()
        {
            DetenerAgente();
            mMSAgente.Characters[mNombre].Hide(null);
        }

        public void DespedirAgente()
        {
            DetenerAgente();
            mMSAgente.Characters[mNombre].Play("Wave");
        }

        public void DetenerAgente()
        {
            mMSAgente.Characters[mNombre].StopAll("Play");
            mMSAgente.Characters[mNombre].StopAll("Speak");
            mMSAgente.Characters[mNombre].StopAll("Move");
        }

        public void MostrarAgente(Form formulario)
        {
            DetenerAgente();
            mMSAgente.BringToFront();
            //agente.Characters[nombre].MoveTo((short)(formulario.DesktopLocation.X + x), (short)(formulario.DesktopLocation.Y + y), cadencia);
            mMSAgente.Characters[mNombre].MoveTo(50, 50, mCadencia);
            //agente.Characters[nombre].MoveTo(50, 50, 0);
            mMSAgente.Characters[mNombre].Show(null);
        }

        public void IniciarBienvenida(Form ObjForm)
        {
            mMSAgente.Characters[mNombre].Balloon.Style = 3;
            mMSAgente.Characters[mNombre].Play("Greet");
            mMSAgente.Characters[mNombre].Play("Announce");
            //mMSAgente.Characters[mNombre].Speak("\\pit=" + voz + "\\ Bievenido al Akinator", null);
            mMSAgente.Characters[mNombre].Speak("Bievenido al Akinator.", null);
            mMSAgente.Characters[mNombre].Play("Blink");
            mMSAgente.Characters[mNombre].MoveTo(100, 300, mCadencia);
            mMSAgente.Characters[mNombre].Play("GestureLeft");
            mMSAgente.Characters[mNombre].Speak("Para jugar, debes pensar en uno de estos animales, " +
                                                "y yo intentaré adivinarlo.", null);
            mMSAgente.Characters[mNombre].Play("DoMagic1");
            mMSAgente.Characters[mNombre].Play("DoMagic2");
        }

        public void LeerPregunta(Form ObjForm, Label lblPregunta, short x, short y)
        {
            DetenerAgente();
            mMSAgente.Characters[mNombre].Balloon.Style = 3;
            mX = x;
            mY = y;
            mMSAgente.Characters[mNombre].MoveTo((short)mX, (short)mY, mCadencia);
            mMSAgente.Characters[mNombre].Play("GestureRight");
            mMSAgente.Characters[mNombre].Speak(lblPregunta.Text, null);
            mMSAgente.Characters[mNombre].Play("DoMagic1");
            mMSAgente.Characters[mNombre].Play("DoMagic2");
        }

        public void LeerTexto(Form ObjForm, string texto, short x, short y)
        {
            DetenerAgente();
            mMSAgente.Characters[mNombre].Balloon.Style = 3;
            mX = x;
            mY = y;
            mMSAgente.Characters[mNombre].MoveTo((short)mX, (short)mY, mCadencia);
            mMSAgente.Characters[mNombre].Play("GestureRight");
            mMSAgente.Characters[mNombre].Speak(texto, null);
            mMSAgente.Characters[mNombre].Play("DoMagic1");
            mMSAgente.Characters[mNombre].Play("DoMagic2");
        }
        
        #endregion

    }
}
