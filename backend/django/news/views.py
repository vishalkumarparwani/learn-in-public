from django.http import JsonResponse
from .models import Article

def article_list(request):
    articles = Article.objects.order_by("-created_at").values(
        "id", "title", "content", "created_at"
    )
    return JsonResponse(list(articles), safe=False)