from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
import json
# Create your views here.
from .models import Laboratory, Student, Hint, Stats


def facePage(request):
    students = Student.objects.all()
    stats = Stats.objects.all().order_by('lab')
    print(stats)
    context = {
        'students': students,
        'stats': stats,
    }

    return render(request, template_name='facePage.html', context=context)




def index(request):
    data = {}
    students = Student.objects.all()
    for student in students:

        data.update({student.group: {'name': student.name, 'rating': student.rating, 'labs': {}}})
        i = 1
        labs = Stats.objects.filter(student=student).filter(status=False).prefetch_related('lab')
        for lab in labs:
            data[student.group]['labs'].update({
                i: {
                    'name': lab.lab.name,
                    'description': lab.lab.description,
                    'status': int(lab.status),
                    'hints': {}
                }
            })

            hints = Hint.objects.filter(lab=lab.lab.id)
            j = 1
            for hint in hints:
                data[student.group]['labs'][i]['hints'].update({j: hint.text})
                j += 1
            i += 1
    return JsonResponse(data)


def table_view(request):
    students = Student.objects.all()
    stats = Stats.objects.all().order_by('lab')
    context = {
        'students': students,
        'stats': stats,
    }

    return render(request, template_name="table.html", context=context)


def update_changes(request):
    if(request.GET):
        stats = Stats.objects.get(pk=request.GET['stats_id'])
        user = Student.objects.get(pk=stats.student.id)
        labs_kt1 = user.labs.filter(kt=1)
        labs_kt2 = user.labs.filter(kt=2)
        labs_kt3 = user.labs.filter(kt=3)
        sum_labs = len(labs)
        lab_point = 100 / sum_labs
        user.rating = lab_point
        if request.GET['status']:
            if stats.status is False:
                user.rating += lab_point
            else:
                user.rating += 0

            stats.status = True


        else:
            stats.status = False
        user.save()
        stats.save()



    return JsonResponse(
        {
            'status':stats.status, 
            'user_id':user.id, 
            'lab_id':request.GET['stats_id'], 
            'kt_1':user.rating_1KT,
            'kt_2':user.rating_2KT,
            'kt_3':user.rating_3KT,
            'rating':user.rating
        })



