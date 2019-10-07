class Sensor {
  private:
    double value;
    String nombre;
    String fecha;
  public:
    Sensor(){

    }

    void SetNombre(String nombre) {
      nombre = nombre;
    }
    
    void SetFecha(String fecha) {
      fecha = fecha;
    }

    void SetValor(double value) {
      value = value;
    }

    String  GetJSON(){
      return "{ \" nombre \" :"+nombre+"}";
    }

};
