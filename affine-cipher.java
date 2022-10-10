import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class AffineCipher {
    private static final String alphabet = "abcdefghijklmnopqrstuvwxyz";
    private static final String alphabet1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter("\n");
        List<Integer> list = new ArrayList<>();
        Collections.addAll(list, 1, 3, 5,7,11,15,17,19,21,23,25);

        System.out.println("1 FOR ENCRYPTION:");
        System.out.println("2 FOR DECRYPTION:");
        System.out.println("3 FOR BRUTEFORCE:");
        System.out.println("Other Key FOR EXIT:");
        int c=sc.nextInt();
        boolean result=false;
        String pt="";
        String ct="";
        String pt1="";
        String ptd="";
        String ct1="";
        String km="";

        String keym="";
        String keya="";

        int kmf=0;
        String ka="";
        int kaf=0;
        int f=0;
        ArrayList<Integer> spaces=new ArrayList<>();
        switch(c){
            case 1:
                while(!result){
                    System.out.println("ENTER Plaintext : ");
                    pt=sc.next();
                    pt1=pt;
                    pt=pt.replaceAll("\\s+","");
                    result = pt.matches("[a-z]+");
                    if(result==false)
                        System.out.println("ENTER CORRECT STRING::");
                }
                for(int i=0;i<pt1.length();i++){
                    if(pt1.charAt(i)==' ') spaces.add(i);
                }
                while (f == 0) {
                    System.out.println("ENTER Multiplicative KEY : ");
                    km = sc.next();
                    result = km.matches("[0-9]+");
                    if (result == false)
                        System.out.println("ENTER CORRECT KEY::");
                    else
                        kmf = Integer.parseInt(km);
                    kmf = kmf % 26;
                    if(list.contains(kmf)) {
                        f = 1;
                    }
                    else {
                        System.out.println("ENTER CORRECT KEY::");
                        System.out.println("Key Must Be::1,3,5,7,11,15,17,19,21,23,25");
                        result=false;
                    }
                }
                f=0;
                while (f == 0) {
                    System.out.println("ENTER Addative KEY : ");
                    ka = sc.next();
                    result = ka.matches("[0-9]+");
                    if (result == false)
                        System.out.println("ENTER CORRECT KEY::");
                    else
                        f = 1;
                }
                kaf= Integer.parseInt(ka);
                kaf = kaf % 26;

                String enc = autoAEncryption(pt,kmf,kaf);
                String enc1 = "";
                StringBuffer str = new StringBuffer(enc);

                for (int i = 0; i < pt1.length(); i++) {
                    for (int j = 0; j < spaces.size(); j++) {
                        if (spaces.get(j) == i) {
                            str.insert(i, ' ');
                        }
                    }

                }
                enc1 = str.toString();
                System.out.println("Plaintext : " + pt1);
                System.out.println("Encrypted : " + enc1);
                break;


            case 2:
                while(!result){
                    System.out.println("ENTER Ciphertext : ");
                    ptd=sc.next();
                    pt1=ptd;
                    ptd=ptd.replaceAll("\\s+","");
                    result = ptd.matches("[A-Z]+");
                    if(result==false)
                        System.out.println("ENTER CORRECT STRING::");
                }
                for(int i=0;i<pt1.length();i++){
                    if(pt1.charAt(i)==' ') spaces.add(i);
                }

                for(int i=0;i<ptd.length();i++){
                    int p1=alphabet1.indexOf(ptd.charAt(i));
                    pt+=alphabet.charAt(p1);
                }
                while (f == 0) {
                    System.out.println("ENTER Multiplicative KEY : ");
                    km = sc.next();
                    result = km.matches("[0-9]+");
                    if (result == false)
                        System.out.println("ENTER CORRECT KEY::");
                    else
                        kmf = Integer.parseInt(km);
                    kmf = kmf % 26;
                    if(list.contains(kmf)) {
                        f = 1;
                    }
                    else {
                        System.out.println("ENTER CORRECT KEY::");
                        System.out.println("Key Must Be::1,3,5,7,11,15,17,19,21,23,25");
                        result=false;
                    }
                }
                f=0;
                while (f == 0) {
                    System.out.println("ENTER Addative KEY : ");
                    ka = sc.next();
                    result = ka.matches("[0-9]+");
                    if (result == false)
                        System.out.println("ENTER CORRECT KEY::");
                    else
                        f = 1;
                }
                kaf= Integer.parseInt(ka);
                kaf = kaf % 26;
                int counterInverse=1;
                while ((kmf*counterInverse)%26!=1){
                    counterInverse+=1;
                }
//                System.out.println(counterInverse);
//                System.out.println(kaf);
                String dec = autoADecryption(pt,counterInverse,kaf);
                String dec1 = "";
                StringBuffer str1 = new StringBuffer(dec);
//                System.out.println(spaces);
                for (int i = 0; i < pt1.length(); i++) {
                    for (int j = 0; j < spaces.size(); j++) {
                        if (spaces.get(j) == i) {
                            str1.insert(i, ' ');
                        }
                    }

                }
                dec1 = str1.toString();
                System.out.println("Encrypted : " + pt1);
                System.out.println("Plaintext : " + dec1);
                break;

            case 3:

                String ciptext = "";
                String ciptext1 = "";
                boolean ctresult = false;
                boolean outerloop = false;
                while (!outerloop) {
                    result = false;
                    ctresult = false;
                    while (!result) {
                        System.out.println("ENTER Plaintext : ");
                        pt = sc.next();
                        pt1 = pt;
                        pt = pt.replaceAll("\\s+", "");
                        result = pt.matches("[a-z]+");
                        if (result == false)
                            System.out.println("ENTER CORRECT STRING::");
                    }

                    while (!ctresult) {
                        System.out.println("ENTER Ciphertext : ");
                        ciptext = sc.next();
                        ciptext1 = ciptext;
                        ciptext = ciptext.replaceAll("\\s+", "");
                        ctresult = ciptext.matches("[A-Z]+");
                        if (ctresult == false)
                            System.out.println("ENTER CORRECT STRING::");
                    }


                    int flag = 1;
                    if (ciptext1.length() != pt1.length()) {
                        System.out.println("Length of both are not same");
                        flag = 0;
                    }
                    int flagC = 1;
                    if (flag == 1) {
                        for (int i = 0; i < pt1.length(); i++) {
                            if (pt1.charAt(i) == ' ') {
                                if (ciptext1.charAt(i) == ' ') {

                                } else {
                                    flagC = 0;
                                }
                            }
                        }
                    }

                    if (flagC == 0) {
                        System.out.println("Spaces are not equal or at same place");
                    }
                    if (flagC == 1 && flag == 1) {
                        outerloop = true;
                    }
                }


                String Encr = "";
                int keyBruteM = 0;
                int keyBruteA = 0;
                int flag1 = 0;
                for (int i = 0; i < 26; i++) {
                    keyBruteA=i;
                    for (int j = 0; j < 26; j++) {
                        keyBruteM=j;
                        Encr = autoAEncryption(pt, keyBruteM,keyBruteA);
                        //System.out.println("KEY:"+i+"  "+Encr);
                        if (Encr.equals(ciptext)) {
                            System.out.println("FOUND Key ADDITIVE:" + i);
                            System.out.println("FOUND Key MULTIPLICATIVE:" + j);
                            flag1 = 1;
                            break;
                        }
                        Encr = "";
                        if(flag1==1) break;
                    }
                    if(flag1==1) break;
                }



                if (flag1 == 0)
                    System.out.println("NO RESULT FOUND");


                break;
        }



    }


    public static String autoAEncryption(String msg,int km,int ka){
        int len = msg.length();
        String encryptMsg = "";
        for(int i=0;i<len;i++){

            int p1=alphabet.indexOf(msg.charAt(i));
            int total = ((p1*km)+ka)% 26;
            encryptMsg += alphabet1.charAt(total);
        }
        //System.out.println(encryptMsg);
        return encryptMsg;
    }


    public static String autoADecryption(String msg,int km,int ka)
    {
        int len = msg.length();
        String decryptMsg = "";
        for(int i=0;i<len;i++){
            int p1=alphabet.indexOf(msg.charAt(i));
            int total = ((p1-ka)*km)% 26;
            if(total<0){
                total+=26;
            }
            decryptMsg += alphabet.charAt(total);
        }
        //System.out.println(decryptMsg);
        return decryptMsg;
    }


}
