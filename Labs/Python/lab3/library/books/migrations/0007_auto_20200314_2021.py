# Generated by Django 2.1.5 on 2020-03-14 20:21

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('books', '0006_auto_20200314_1034'),
    ]

    operations = [
        migrations.AlterField(
            model_name='books',
            name='cover_pic',
            field=models.ImageField(default='/run/media/tharwat-manjaro/Linux-Data/Labs/Labs/Python/lab3/library/books/static/400px x 600px-r01BookNotPictured.jpg', upload_to='books/'),
        ),
    ]
