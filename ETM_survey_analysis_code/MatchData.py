import pandas as pd
import csv
def combinetwolist(index,pre,post):
    # This function combine two list into one list. 
    # The first element in combine list is the ID.
    conbinelist = [index]
    for i in range(2,len(pre)):
        conbinelist.append(pre[i])
        conbinelist.append(post[i])
        
    return conbinelist
    
    

def main():
    # convert csv to list
    pre_df = pd.read_csv(r'D:\ETM\Testing data\Aug17th\ETM pre survey_modified.csv')    # import pre survey data; r is to allow space in address
    post_df = pd.read_csv(r'D:\ETM\Testing data\Aug17th\ETM post survey_modified.csv')  # import post survey data
    pre_list = pre_df.values.tolist()
    post_list = post_df.values.tolist()
    Paired_list = []    
    fields = ['ID', 'Q1pre','Q1post','Q2pre','Q2post','Q3pre','Q3post','Q4pre','Q4post','Q5pre','Q5post',
        'Q6pre','Q6post','Q7pre','Q7post','Q8pre','Q8post','Q9pre','Q9post','Q10pre','Q10post',
        'Q11pre','Q11post','Q12pre','Q12post','Q13pre','Q13post','Q14pre','Q14post','Q15pre','Q15post',
        'Q16pre','Q16post','Q17pre','Q17post','Q18pre','Q18post']   # header for paired csv 
    
    # Using double for loop for pairing
    for i in range(1, len(pre_list)):
        for j in range(1, len(post_list)):
            if(pre_list[i][0].lower()) == (post_list[j][0].lower()) and (pre_list[i][1].lower()) == (post_list[j][1].lower()):  # if both first name and last name are matched
                #print("pre name is", pre_list[i][0],pre_list[i][1])
                #print("post name is", post_list[j][0],post_list[j][1])
                Paired_list.append(combinetwolist(i,pre_list[i],post_list[j]))   # paired pre and post lists of one students into one list. Attach it to output list 
                post_list.remove(post_list[j])  # removed matched name from post list to speed up running 
                break   # Stop searching loop once find matched name in post survey 
                
                
    #print(len(post_list))
    
    with open(r'D:\ETM\Testing data\Aug17th\paired result.csv', 'w', newline='') as f:
        # using csv.writer method from CSV package to export paired list
        write = csv.writer(f)
        write.writerow(fields)
        write.writerows(Paired_list)

if __name__=='__main__':
    main()