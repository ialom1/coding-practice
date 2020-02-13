import json

mydict = {
  "names": [
    "Shakib", "Sarowar"
  ], 
  "locations": [
    "Dhaka", "Sylhet", "Khulna"
  ], 
  "organizations": [
    "BNP", "BRTC", "BEXIMCO"
  ], 
  "events": [
      "New Year Party 2021", "Farewell CSE 15", "Concert 2020"
    ], 
  "dates": [
    "Sunday", "Friday"
  ],
  "others" :[]
}

# print(mydict)
res = {}
for k in mydict:
    val = ""
    for v in mydict[k]:
        val += (v + ", ")
    res[k] = val[:-2]


res_json = json.dumps(res, indent=1)
print(res_json)


# {
#  "names": "Shakib, Sarowar",
#  "locations": "Dhaka, Sylhet, Khulna",
#  "organizations": "BNP, BRTC, BEXIMCO",
#  "events": "New Year Party 2021, Farewell CSE 15, Concert 2020",
#  "dates": "Sunday, Friday",
#  "others": ""
# }