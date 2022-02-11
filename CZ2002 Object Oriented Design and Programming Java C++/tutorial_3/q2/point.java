/**
 * point
 */
package q2;
public class point {

    protected int x;
    protected int y;

    public point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public String toString(){

        return "point";
    }

    public void setPoint(int x, int y){
        this.x = x;
        this.y=y;
    }
    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }
}