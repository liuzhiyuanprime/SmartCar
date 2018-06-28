
void delay(unsigned int xms)
{
unsigned int i,j;
for(i=xms;i>0;i--) //i=xms即延时约xms毫秒
for(j=112;j>0;j--)
_nop_();
}