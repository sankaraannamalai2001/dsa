import java.util.*;
class wordMatrix{
    public static boolean checkMatch(char[][] mat,String s,int i,int j,int r,int c,int l,boolean visited[][])
    {
        if(i>=r ||j>=c || i<0 || j<0)
            return false;
        if(mat[i][j]!=s.charAt(l))
            return false;
        if(visited[i][j]==true)
            return false;
        visited[i][j]=true;
        
        if(l==s.length()-1){
            mat[i][j] = '#';
            return true;
        }
        boolean res;
        res= checkMatch(mat,s,i+1,j,r,c,l+1,visited)||checkMatch(mat,s,i,j+1,r,c,l+1,visited)||checkMatch(mat,s,i-1,j,r,c,l+1,visited)||checkMatch(mat,s,i,j-1,r,c,l+1,visited);
        if(res==true){
            mat[i][j]='#';
            return true;
        }
        visited[i][j]=false;
        return false;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt();
        int c=sc.nextInt();
        char a[][]=new char[r][c];
        sc.nextLine();
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

            String s=sc.nextLine();
            boolean res=false;
            boolean visited[][]=new boolean[r][c];
          for(int i=0;i<r;i++)
          {
            for(int j=0;j<c;j++)
            {
                 if(a[i][j]==s.charAt(0))
                res=res||checkMatch(a,s,i,j,r,c,0,visited);
            }
          }  
            System.out.println(res);
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    System.out.print(a[i][j]+" ");
                }
                System.out.println();
            }
    }
}