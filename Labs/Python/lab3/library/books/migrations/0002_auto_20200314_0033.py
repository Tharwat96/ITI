# Generated by Django 2.0 on 2020-03-14 00:33

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('books', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='books',
            name='cover_pic',
            field=models.ImageField(default='/run/media/tharwat-manjaro/Linux-Data/Labs/Labs/Python/lab3/library/books/media/400px x 600px-r01BookNotPictured.jpg', upload_to=''),
        ),
        migrations.AddField(
            model_name='books',
            name='description',
            field=models.TextField(default='No description given yet.'),
        ),
    ]
