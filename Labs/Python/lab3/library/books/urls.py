from django.conf import settings
from django.conf.urls.static import static
from django.urls import path

from . import views

urlpatterns = [
                  path('', views.index, name='index'),
                  path('book_details/<int:book_id>', views.book_details, name='book_details'),
                  path('author/<int:author_id>', views.author_details, name='author_details'),
              ] + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
