public class Animal {
    private double peso;
    private String especie;
            ;
    //gerar getters and setters

    public Animal() {
    //padrão
    }

    public Animal(double peso, String especie) {
        super();
        this.peso = peso;
        this.especie = especie;
    }

    public static void main(String[] args) {
        Animal a = new Animal();
        a.setPeso(5.5);
        a.setEspecie("Mamiferos");
        System.out.println("Peso: " + a.getPeso() + " Especie: " + a.getGrupo());
        Animal b = new Animal(6.0, "Aves");
        System.out.println("Peso: " + b.getPeso() + " Especie: " + b.getGrupo());