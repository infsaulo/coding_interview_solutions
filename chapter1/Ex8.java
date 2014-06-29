public class Ex8
{
    // Return true if s2 is a substring of s1, false otherwise.
    private static boolean isSubstring(String s1, String s2)
    {
        return s1.contains(s2);    
    }

    // Is string s2 a rotation of string s1? 
    private static boolean isRotation(String s1, String s2)
    {
        if(s1.length() == s2.length() && s1.length() > 0)
        {
            /*
             * Considering s2 is split in two parts x and y, if s2 is
             * a rotation of s1, we can assume that:
             * s1 = xy
             * s2 = yx
             * s1s1 = xyxy, so:
             * s2 is a substring of s1s1
             */
             String s1s1 = s1 + s1;
             return isSubstring(s1s1, s2);
        }

        return false;
    }

    public static void main(String[] args)
    {
        String s1 = args[0], s2 = args[1];
        System.out.println(isRotation(s1, s2));
    }
}
