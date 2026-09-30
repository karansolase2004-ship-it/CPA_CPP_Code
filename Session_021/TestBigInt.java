// Lack of operator overloading in java results in 
// tedious syntax patters while manipulating objects 
// of user defined data types (class types)

public class TestBigInt{
    public static void main(String[] args){
        BigInt n1 = new BigInt(35434635236363); 
        BigInt n2 = new BigInt(6325366252565); 
        BigInt n3 = new BigInt(3636473636); 

        BigInt result_1 = n1.add(n2).sub(n3); 
    }
}; 
