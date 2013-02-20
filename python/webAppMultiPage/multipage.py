import webapp2
import mysql.connector
class MainPage(webapp2.RequestHandler):
  def get(self):
      self.response.headers['Content-Type'] = 'html'
      index=open('index.html')
      self.response.out.write(index.read())

class SecondPage(webapp2.RequestHandler):
  def get(self):
    sql=mysql.connector.connect(user='root',
                                password='wordpass',
                                host='localhost',
                                database='users')
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
