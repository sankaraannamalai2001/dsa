import java.util.*;
class wordsMatrix{
    public static boolean checkMatch(char[][] mat,String s,int i,int j,int r,int c,int l)
    {
        if(i>=r ||j>=c || i<0 || j<0 || mat[i][j]=='#')
            return false;
        if(mat[i][j]!=s.charAt(l))
            return false;
        char temp=mat[i][j];
        mat[i][j]='#';
        
        if(l==s.length()-1){
            // mat[i][j] = '#';
            return true;
        }
        boolean res;
        res= checkMatch(mat,s,i+1,j,r,c,l+1)||checkMatch(mat,s,i,j+1,r,c,l+1)||checkMatch(mat,s,i-1,j,r,c,l+1)||checkMatch(mat,s,i,j-1,r,c,l+1);
        if(res==true){
            // mat[i][j]='#';
            return true;
        }
        // visited[i][j]=false;
        mat[i][j]=temp;
        return false;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of rows and columns");
        int r=sc.nextInt();
        int c=sc.nextInt();
        char a[][]=new char[r][c];
        sc.nextLine();
        System.out.println("Enter the character matrix");
        String temp;
         for(int i=0;i<r;i++)
            {
                temp=sc.nextLine();
                String b[]=temp.split(" "); 
                for(int j=0;j<c;j++)
                {
                    a[i][j]=b[j].charAt(0);   
                }
            }
            System.out.println("Enter the number of strings");
            int n=sc.nextInt();
            String s[]=new String[n];
            for(int i=0;i<n;i++)
            s[i]=sc.nextLine();
            boolean res=false;
            boolean visited[][]=new boolean[r][c];
            List<String>l=new ArrayList<String>();
        for(int k=0;k<n;k++)
        {
           for(int i=0;i<r;i++)
              {
                for(int j=0;j<c;j++)
                {
                     if(a[i][j]==s[k].charAt(0))
                    res=res||checkMatch(a,s[k],i,j,r,c,0);
                }
              }
              if(res==true)
              l.add(s[k]);
        }
        for(String e:l)
        {
            System.out.print(e+" ");
        }
            
            // System.out.println(res);
            // for(int i=0;i<r;i++)
            // {
            //     for(int j=0;j<c;j++)
            //     {
            //         System.out.print(a[i][j]+" ");
            //     }
            //     System.out.println();
            // }
    }
}
