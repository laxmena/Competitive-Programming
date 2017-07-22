from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import letter, A4
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Image
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle


#Change values here to change text formating in pdf generated
file_path = 'home/result.pdf'

fontsize = 12
linespace = 12
a4height = 841
topmargin = 72
bottommargin = 72
rightmargin = 72
leftmargin = 72
lines_left = (a4height-topmargin-bottommargin)//24

file = []

#Content is the list of elements, stored in tuples, first element of the tuple is the content,
#and second element is the height

content = [("Content 1",5),("Content 2",4),("Content 3",5),("Content 4",2),("Content 5",6),("Content 6",8),("Content 7",29)]

doc = SimpleDocTemplate(file_path,
                        pagesize=A4,
                        rightmargin=rightmargin,
                        leftmargin=leftmargin,
                        topMargin=topmargin-12,
                        bottomMargin=bottommargin)

styles = getSampleStyleSheet()
styles.add(ParagraphStyle(ptext))

#Font size of the text is 12, A4 page has height of 841, and width of 595 points
#Line Space between each line is set to 12
#Top and Bottom Margin are 1 e=inch each,ie 72 points each.
#Effective Page height would be: 697
#So we can write 28 lines, and we will have 29 line spaces left in between


for i in content:
    text,height = i[0],i[1]
    if height >= lines_left:
            while(lines_left>0):
                file.append(Spacer(1, 12))
                file.append(Spacer(1, 12))
                lines_left -= 1
            lines_left = 29
            
    for j in range(height):
        ptext = '%d:<font size=%d>%s</font>' % (j+1,fontsize,text)
        file.append(Spacer(1, linespace))
        file.append(Paragraph(ptext, styles["Normal"])) 
    lines_left -= height
            
doc.build(file)