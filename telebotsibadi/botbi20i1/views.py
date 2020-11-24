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
        if(request.GET['status']):
            stats.status = True
        else:
            stats.status = False
        stats.save()
        user = stats.student
        labs = user.labs.all()
        print(labs)
        return HttpResponse('True')
    return HttpResponse('False') 