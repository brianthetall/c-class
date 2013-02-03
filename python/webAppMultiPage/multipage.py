import webapp2
#import os
#import index.html
class MainPage(webapp2.RequestHandler):
  def get(self):
      self.response.headers['Content-Type'] = 'html'#'text/plain'
#      self.response.out.write(os.path())
#read in HTML file and write it.....
      index=open('index.html')
#      for line in index.input():
      self.response.out.write(index.read())

class SecondPage(webapp2.RequestHandler):
  def get(self):
    self.response.headers['Content-Type'] = 'html'
    self.response.write("""
<html><head>
<title>Welcome In!</title></head>
<body>You made it past the login
</body>
</html>
""")

app = webapp2.WSGIApplication([('/', MainPage),('/second',SecondPage)],
                              debug=True)
