#include "../include/GV.h"
#include <math.h>
#include <stdio.h>

//Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[/
// ÇQéüå≥ÉxÉNÉgÉã
//Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[/
typedef struct {
    double x, y;
} Vector2_t;


//Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[/
// diff Å© ÉxÉNÉgÉã p - q
//Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[Å[/
void Vector2Diff(Vector2_t *diff, const Vector2_t *p, const Vector2_t *q){
    diff->x = p->x - q->x;
    diff->y = p->y - q->y;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
// ÉxÉNÉgÉã p Ç∆ q ÇÃì‡êœ 
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double Vector2InnerProduct(const Vector2_t *p, const Vector2_t *q){
    return p->x * q->x + p->y * q->y;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
// ÉxÉNÉgÉã p Ç∆ q ÇÃäOêœ 
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double Vector2OuterProduct(const Vector2_t *p, const Vector2_t *q){
    return p->x * q->y - p->y * q->x;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//ì_Ç∆ê¸ï™Ç∆ÇÃãóó£ÇãÅÇﬂÇÈ
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double get_distance(double x, double y, double x1, double y1, 
                    double x2, double y2){
    double dx,dy,a,b,t,tx,ty;
    double distance;
    dx = (x2 - x1); dy = (y2 - y1);
    a = dx*dx + dy*dy;
    b = dx * (x1 - x) + dy * (y1 - y);
    t = -b / a;
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    tx = x1 + dx * t;
    ty = y1 + dy * t;
    distance = sqrt((x - tx)*(x - tx) + (y - ty)*(y - ty));
    return distance;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//ì_Ç∆ì_Ç∆ÇÃãóó£Çï‘Ç∑
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double get_pt_and_pt(pt_t p1, pt_t p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//ì_Ç™â~ÇÃíÜÇ…Ç†ÇÈÇ©Ç«Ç§Ç©
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double question_point_and_circle(pt_t p, pt_t rp,double r){
    double dx=p.x-rp.x,dy=p.y-rp.y;
    if (dx * dx + dy * dy < r * r) {
        return 1;//Ç†ÇË
    }
    else {
        return 0;//Ç»Çµ
    }
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//ì¸ÇÍë÷Ç¶
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
void swap_double(double *n, double *m){
    double t=*m;
    *m=*n;*n=t;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//ÇRì_Ç©ÇÁäpìxÇï‘Ç∑
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
double get_sita(pt_t pt0,pt_t pt1,pt_t rpt){

    // ÉxÉNÉgÉã CÅ®P Ç∆ CÅ®Q ÇÃÇ»Ç∑äpÉ∆Ç®ÇÊÇ—âÒì]ï˚å¸ÇãÅÇﬂÇÈ
    Vector2_t c, p, q; /* ì¸óÕÉfÅ[É^ */
    Vector2_t cp;      /* ÉxÉNÉgÉã CÅ®P */
    Vector2_t cq;      /* ÉxÉNÉgÉã CÅ®Q */
    double s;          /* äOêœÅF(CÅ®P) Å~ (CÅ®Q) */
    double t;          /* ì‡êœÅF(CÅ®P) ÅE (CÅ®Q) */
    double theta;      /* É∆ (ÉâÉWÉAÉì) */

    // cÅCpÅCq Çèäñ]ÇÃílÇ…ê›íËÇ∑ÇÈ
    c.x = pt0.x;    c.y = pt0.y;
    p.x = pt1.x;    p.y = pt1.y;
    q.x = rpt.x;    q.y = rpt.y;

    // âÒì]ï˚å¸Ç®ÇÊÇ—äpìxÉ∆ÇåvéZÇ∑ÇÈ
    Vector2Diff(&cp, &p, &c);          /* cp Å© p - c   */
    Vector2Diff(&cq, &q, &c);          /* cq Å© q - c   */
    s = Vector2OuterProduct(&cp, &cq); /* s Å© cp Å~ cq */
    t = Vector2InnerProduct(&cp, &cq); /* t Å© cp ÅE cq */
    theta = atan2(s, t);
    return theta;
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
//í∑ï˚å`Ç∆â~Ç∆ÇÃìñÇΩÇËÇîªíËÇ∑ÇÈ
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
int hitjudge_square_and_circle(pt_t pt[4], pt_t rpt, double r){
    int i;
    double x=rpt.x,y=rpt.y;
	double theta,theta2;

    //â~ÇÃíÜÇ…í∑ï˚å`ÇÃÇSì_ÇÃÇ§ÇøÇ«ÇÍÇ©Ç™Ç†ÇÈÇ©Ç«Ç§Ç©îªíË
    for(i=0;i<4;i++){
        if(question_point_and_circle(pt[i],rpt,r)==1){
            return 1;//Ç†Ç¡ÇΩ
        }
    }
    

    //í∑ï˚å`ÇÃíÜÇ…ï®ëÃÇ™ì¸ÇËçûÇÒÇ≈Ç¢ÇÈÇ©Ç«Ç§Ç©ÇîªíËîªíË

    theta =get_sita(pt[0],pt[1],rpt);//3ì_ÇÃê¨Ç∑äp1
    theta2=get_sita(pt[2],pt[3],rpt);//3ì_ÇÃê¨Ç∑äp2

    if(0<=theta && theta<=PI/2 && 0<=theta2 && theta2<=PI/2){
        return 1;//ì¸Ç¡ÇƒÇ¢ÇÈ
    }

    //ê¸ï™Ç∆ì_Ç∆ÇÃãóó£ÇãÅÇﬂÇÈ
    for(i=0;i<4;i++){
        if(get_distance(rpt.x,rpt.y,pt[i].x,pt[i].y,pt[(i+1)%4].x,pt[(i+1)%4].y)<r){
            return 1;//ÉqÉbÉgÇµÇƒÇ¢ÇÈ
        }
    }
    return 0;//ìñÇΩÇ¡ÇƒÇ»Ç¢
}


//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
// ÉåÅ[ÉUÅ[èàóù
//Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|Å|/
int out_lazer(){
    int i,j;
    pt_t sqrp[4],rpt={ch.x,ch.y};//í∑ï˚å`ÇÃ4ì_Ç∆â~ÇÃíÜêS
    //ÉåÅ[ÉUÅ[ï™ÉãÅ[Év
    for(i=0;i<LAZER_MAX;i++){
        //ÉåÅ[ÉUÅ[Ç™ìoò^Ç≥ÇÍÇƒÇ¢ÇƒÅAìñÇΩÇËîªíËÇÇ∑ÇÈê›íËÇ»ÇÁ
        if(lazer[i].flag>0 && lazer[i].hantei!=0){
            for(j=0;j<4;j++){//ÉåÅ[ÉUÅ[ÇÃ4ì_Çê›íË
                sqrp[j].x=lazer[i].outpt[j].x;
                sqrp[j].y=lazer[i].outpt[j].y;
            }
            //í∑ï˚å`Ç∆â~Ç∆ÇÃê⁄êGîªíË
            if(hitjudge_square_and_circle(sqrp,rpt,CRANGE)){
                return 1;//ìñÇΩÇ¡ÇΩ
            }
        }
    }
    return 0;//ìñÇΩÇ¡ÇƒÇ»Ç¢
}